int seq_search(int * a , int size ,int e)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]==e)
            return i;
    }
    return 0;
}
int binary_search_aux(int *a ,int start , int end,int e)
{
  int mid = start+((end-start)/2);
  if(a[mid]>e)
  binary_search_aux(a,start,mid-1,e);
  else if(a[mid]<e)
    binary_search_aux(a,mid+1,end,e);
  else
    return mid;

}
int binary_search(int * a , int size ,int e)
{
return binary_search_aux(a,0,size-1,e);
}
