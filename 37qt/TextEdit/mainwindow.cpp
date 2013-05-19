#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    saveFlag=0;
    fileName="newfile";
    //Set the window title
    this->setWindowTitle(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    //判断当前文件是否已保存
    isSaved();
    saveFlag=1;
    fileName="newfile";
    this->setWindowTitle(fileName);

    //清空已存在的文本
    ui->textEdit->clear();
}

void MainWindow::isSaved()
{
    if(ui->textEdit->document()->isModified()){
	QMessageBox box;
	box.setText("UnSaved The Current File.Do you want to save it?");
	box.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	if(box.exec()==QMessageBox::Yes){
	    saveFile();
	}
    }
}
void MainWindow::saveFile()
{
    //If file has exited on disk
    if(saveFlag){
	saveToDisk(fileName);
    }
    else{
	saveFileAs();
    }
    //设置此处是为了保存以后在进行关闭操作的时候不再出现为保存的提示
    ui->textEdit->document()->setModified(false);
}

void MainWindow::saveFileAs()
{
	//当textEdit里面有内容时，才进行另存为操作
	if(ui->textEdit->toPlainText().length()>0){
	    //获取用户输入的文件名
	    QString name=QFileDialog::getSaveFileName(this);
	    if(!name.isEmpty()){
		    if(!saveToDisk(name)){
			qDebug("Failed to save file...");
		    }
		    else{
			qDebug("Success to save file");
			ui->textEdit->document()->setModified(false);
		    }
	    }
      }
}

void MainWindow::Exit()
{
	isSaved();
	//可以通过this调用close()关闭程序
	//this->close();
	//或者通过 qApp关闭程序
	qApp->quit();
}

bool MainWindow::saveToDisk(const QString& file)
{
    QFile myFile(file);
    if(!myFile.open(QFile::WriteOnly|QFile::Text)){
	QMessageBox box;
	box.setWindowTitle("Warning");
	box.setIcon(QMessageBox::Warning);
	box.setText("Save file failed!");
	box.setStandardButtons(QMessageBox::Ok);
	box.exec();
	return false;
    }
    QTextStream out(&myFile);
//    QString prevContent(out.readAll());
//    QString currContent(ui->textEdit->toPlainText());
//    for(int i=prevContent.length()-1;i<currContent.length();++i)
//	chText+=currContent[i];
//    //写的时候，我们只写不同的内容
    out<<ui->textEdit->toPlainText();
    myFile.close();
    saveFlag=1;
    fileName=file;
    setWindowTitle(fileName);
    return true;
}

void MainWindow::on_actionNew_triggered()
{
    newFile();
}

void MainWindow::on_actionSaveAS_triggered()
{
    saveFileAs();
}

void MainWindow::on_actionSafe_triggered()
{
    saveFile();
}

void MainWindow::on_actionOpen_triggered()
{
    //Check is saved
    isSaved();
    //Get the opening file name
    QString openFileName=QFileDialog::getOpenFileName(this);
    QFile openFile(openFileName);
    if(!openFile.open(QFile::ReadOnly|QFile::Text)){
	qDebug("failed to open ");
	return;
    }
    //Create a text stream object
    QTextStream in(&openFile);
    //Read the file and dispaly it in the TextEdit widget
    ui->textEdit->setText(in.readAll());

    fileName=openFileName;
    setWindowTitle(fileName);
    saveFlag=1;
}

void MainWindow::on_actionExit_triggered()
{
	Exit();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionFind_triggered()
{
    QDialog* fDialog = new QDialog(this);
    QLabel*  label = new QLabel("&Find:",fDialog);
    findLineEdit = new QLineEdit(fDialog);
    label->setBuddy(findLineEdit);

    QPushButton* myok = new QPushButton("OK");
    QPushButton* mycancel = new QPushButton("Cancel");

    QHBoxLayout* up = new QHBoxLayout;
    up->addWidget(label);
    up->addWidget(findLineEdit);
    QHBoxLayout* down = new QHBoxLayout;
    down->addWidget(mycancel);
    down->addWidget(myok);
    QVBoxLayout* global = new QVBoxLayout;
    global->addLayout(up);
    global->addLayout(down);

    fDialog->setLayout(global);
    fDialog->show();
    //链接信号和槽函数
    connect(mycancel,SIGNAL(clicked()),fDialog,SLOT(close()));
    connect(myok,SIGNAL(clicked()),this,SLOT(findString()));

}

void MainWindow::findString()
{
     QString s = this->findLineEdit->text();
     if(! ui->textEdit->find(s)){
	 QMessageBox box;
	 box.setWindowTitle("Warning");
	 box.setIcon(QMessageBox::Warning);
	 box.setText("Can't find.");
	 box.setStandardButtons(QMessageBox::Ok);
	 box.show();
	 box.exec();
     }
}
