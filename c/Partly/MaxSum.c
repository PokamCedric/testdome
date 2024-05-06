
void twoMax(int *arr,int size){
    int i,firstlargest=0,secondlargest=0;
    for(i=0;i<size;i++){
        if(arr[i]>firstlargest){
            secondlargest=firstlargest;
            firstlargest=arr[i];
        }
      }
}


nth_element(first, nth, last)
{ 
  if (first == last || nth == last)
    return;

  introselect(first, nth, last, log2(last - first) * 2);
}

introselect(first, nth, last, depth_limit)
{
  while (last - first > 3)
  {
      if (depth_limit == 0)
      {
          // [NOTE by editor] This should be median-of-medians instead.
          // [NOTE by editor] See Azmisov's comment below
          heap_select(first, nth + 1, last);
          // Place the nth largest element in its final position.
          iter_swap(first, nth);
          return;
      }
      --depth_limit;
      cut = unguarded_partition_pivot(first, last);
      if (cut <= nth)
        first = cut;
      else
        last = cut;
  }
  insertion_sort(first, last);
}