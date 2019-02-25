int matrix_add(int *o,int *a,int *b,int satir,int sutun)
{
	int i,j;
	for (i=0;i<satir;i++)
	{
		for (j=0;j<sutun;j++)
		{
			o[i*sutun+j] = a[i*sutun+j] +b[i*sutun+j];
		}	
	}
}
int matrix_mul(int *o,int *a,int *b,int n1,int n2,int n3)
{
	int i,j,k;
	for (i=0;i<n1;i++)
	{
		for (j=0;j<n3;j++)
		{
			o[i*n3+j] = 0;
			for (j=0;j<n2;j++)
			{
			  o[i*n3+j] += a[i*n2+k]  * b[k*n3+j];
			}
		}	
	}
}

int matrix_sub(int *o,int *a,int *b,int satir,int sutun)
{
	int i,j;
	for (i=0;i<satir;i++)
	{
		for (j=0;j<sutun;j++)
		{
			o[i*sutun+j] = a[i*sutun+j] - b[i*sutun+j];
		}	
	}
}


