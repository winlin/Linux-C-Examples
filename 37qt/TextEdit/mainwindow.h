#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    //判断当前文件是否已保存,如果没有保存则提示用户保存
    void isSaved();
    //创建新文件
    void newFile();
    //打开文件
    void openFile();
    //保存文件
    void saveFile();
    //另存为
    void saveFileAs();
    //关闭文件
    void Exit();

    //将文件回写到磁盘
    bool saveToDisk(const QString& file);

private slots:
    void on_actionNew_triggered();

    void on_actionSaveAS_triggered();

    void on_actionSafe_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionRedo_triggered();

    void on_actionFind_triggered();
    //自定义的槽函数
    void findString();

private:
    Ui::MainWindow *ui;

private:
    bool saveFlag;
    QString fileName;

    //用于查找对话框中的QLineEdit
    //作为数据成员便于获得用户要查找的关键字
    QLineEdit* findLineEdit;
};

#endif // MAINWINDOW_H
