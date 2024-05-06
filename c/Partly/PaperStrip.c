#include <stdio.h>

int index(int* src, const size_t length, const int cmp, int start){
    if(start < 0){
        start = 0;
    }
  for(size_t i = start; i < length + start; i++){
    if(cmp == src[i % length]){
      return i;
    }
  }
  return -1;
}

int min_pieces(int* original, int* desired, int length)
{
	int nbre = 0;
	int foundPrev = -2;
	for(size_t i = 0U; i < length; i++){
		int found =	index(original, length, desired[i], 0 );

		if(-1 != found){
			if( (foundPrev + 1) != found){
				nbre++;
			}
			foundPrev = found;
		}
		
	}
    return nbre;
}

#ifndef RunTests
int main()
{
    int original[] = {1, 4, 3, 2, 6, 7, 9};
    int desired[] = {1, 6, 7, 4, 9, 3, 2};
    printf("%d\n", min_pieces(original, desired, 7));

    return 0;
}
#endif


#include <stdio.h>

int index(int* src,  int length, const int cmp, int start){
    static int calls = 0;
    
    if(start < 0){
        start = 0;
    }
  for(int i = start; i < length + start; i++){
    calls++;
        printf("calls: %d\n", calls);
        printf("start: %d, start+l: %d, imodl: %d\n", start, start+length, i % length);

    if(cmp == src[i % length]){
      printf("found index: %d\n", i);
      return i;
    }
  }
      printf("calls: %d\n", calls);

  return -1;
}

int min_pieces(int* original, int* desired, int length)
{
	int nbre = 0;
	int foundPrev = -2;
	for(size_t i = 0U; i < length; i++){
		int found =	index(original, length, desired[i], (foundPrev+1) % length  );

		if(-1 != found){
			if( (foundPrev + 1) != found){
				nbre++;
			}
			foundPrev = found;
		}
		
	}
    return nbre;
}

#ifndef RunTests
int main()
{
    int original[] = {1, 4, 3, 2, 6, 7, 9};
    int desired[] = {1, 6, 7, 4, 9, 3, 2};
    printf("%d\n", min_pieces(original, desired, 7));

    return 0;
}
#endif

#include <stdio.h>

int index(int* src,  int length, const int cmp, int start){
    static int calls = 0;
    
    if(start < 0){
        start = 0;
    }
  for(int i = start; i < length + start; i++){
    calls++;
        printf("calls: %d\n", calls);
        printf("start: %d, start+l: %d, imodl: %d\n", start, start+length, i % length);

    if(cmp == src[i % length]){
      return i;
    }
  }
      printf("calls: %d\n", calls);

  return -1;
}

int min_pieces(int* original, int* desired, int length)
{
	int nbre = 0;
	int foundPrev = -2;
	for(int i = 0U; i < length; i++){
		int found =	index(original, length, desired[i], 0 );
            printf("found index: %d, i=%d\n", found, i);
        found++;
        if(found < length && i <length){
     		while( original[found] == desired[i+1]){
    		    i++;
                printf("while found index: %d, i=%d\n", found, i);
    		};           
        }

        nbre++;
            printf("nbre: %d\n", nbre);
	}
    return nbre;
}

#ifndef RunTests
int main()
{
    int original[] = {1, 4, 3, 2, 6, 7, 9};
    int desired[] = {1, 6, 7, 4, 9, 3, 2};
    printf("%d\n", min_pieces(original, desired, 7));

    return 0;
}
#endif