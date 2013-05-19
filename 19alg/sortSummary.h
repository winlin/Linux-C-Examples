void bubble(int * a,int n)
{
	for(int i=0;i<n-1;++i){
		bool flag=true;
		for(int j=0;j<n-i-1;++j){
			if(a[j+1]<a[j]){
				swap(a[j+1],a[j]);
				flag=false;
			}
		}
		if(flag)
			break;
	}
}

void bubbleB(int* a,int n)
{
	for(int i=0;i<n-1;++i){
		bool flag=true;
		for(int j=0;j<n-i-1;++j){
			if(a[j+1]>a[j]){
				swap(a[j+1],a[j]);
				flag=false;
			}
		}
		if(flag)
			break;
	}
}

void chooseSort(int* a,int n)
{
	int min;
	for(int i=0;i<n-1;++i){
		min=i;
		for(int j=i;j<n;++j){
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
			swap(a[i],a[min]);
	}
}
void chooseSortB(int* a,int n)
{
	int max;
	for(int i=n-1;i>0;--i){
		max=i;
		for(int j=i;j>=0;--j){
			if(a[j]>a[max])
				max=j;
		}
		if(max!=i)
			swap(a[i],a[max]);
	}
}

void insertSort(int* a,int n)
{
	for(int i=1;i<n;++i){
		int x=a[i];
		int j;
		for(j=i;j>0&&a[j-1]>x;--j)
			a[j]=a[j-1];
		a[j]=x;
	}
}

void insertSort(int* a,int n)
{
	for(int i=1;i<n;++i){
		int x=a[i];
		int j;
		/*j表示要插入的位置*/
		for(j=i;j>0&&a[j-1]>x;--j)
			a[j]=a[j-1];
		a[j]=x;
	}
}
void insertSortB(int *a,int n)
{
	for(int i=1;i<n;++i){
		int x=a[i];
		int j;
		for(j=i;j>0&&a[j-1]<x;--j)
			a[j]=a[j-1];
		a[j]=x;
	}
}

void quickSort(int* a,int n)
{
	if(n<1)
		return;
	int l=0;
	int r=n-1;
	int m=a[l];
	while(l<r){
		while(l<r && m<=a[r])--r;
		a[l]=a[r];
		while(l<r && m>=a[l])++l;
		a[r]=a[l];
	}
	a[l]=m;
	quickSort(a,l);
	quickSort(a+l+1,n-l-1);
}

void quickSortB(int* a,int b)
{
	if(n<1)
		return;
	int l=0;
	int r=n-1;
	int m=a[l];
	while(l<r){
		while(l<r && m>=a[r])--r;
		a[l]=a[r];
		while(l<r && m<=a[l])++l;
		a[r]=a[l];
	}
	a[l]=m;
	quickSortB(a,l);
	quickSortB(a+l+1,n-l-1);
}










