#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int n;
	int* elements;
} t_vector;

// t_vector repetidas(t_vector album, t_vector novas){
//     int k = 0;
//     t_vector fig_repetidas;
// 	fig_repetidas.n = 0;
// 	fig_repetidas.elements = (int*)malloc((fig_repetidas.n+1)*sizeof(int));
//     for (int i = 0; i < album.n; i++) {
//         for (int j = 0; j < novas.n; j++) {
//             if (album.elements[i] == novas.elements[j]) {
//                 fig_repetidas.elements[k] = album.elements[i];
//                 k = k+1;
// 				fig_repetidas.n = k;
// 			}
// 		}
//     }
	
//     return fig_repetidas;
// }

t_vector repetidas(t_vector album, t_vector novas){
    t_vector fig_repetidas;
	fig_repetidas.n = 0;
	fig_repetidas.elements = (int*)malloc((album.n+1)*sizeof(int));

	int j = 0;
	int i = 0;
	int k = 0;
	while (i <= album.n && j <= novas.n){
		if (album.elements[i] < novas.elements[j]) {
			i++;
		}
		else {
			if (novas.elements[j] < album.elements[i]) {
				j++;
			} else {
                fig_repetidas.elements[k] = album.elements[i];
				fig_repetidas.n = k;
				k++;
				i++;
				j++;
			}
			
		}
	}
	
	
    return fig_repetidas;
}




int main() {
	int i, j, k;
	t_vector album, novas, reps;
	scanf("%d", &album.n);
	album.elements = (int*)malloc((album.n+1)*sizeof(int));
	for(i = 0; i < album.n; i++){
		scanf("%d", &(album.elements[i]));
	}
	album.elements[i] = INT_MAX;
	
	scanf("%d", &novas.n);
	novas.elements = (int*)malloc((novas.n+1)*sizeof(int));
	for(i = 0; i < novas.n; i++){
		scanf("%d", &(novas.elements[i]));
	}
	novas.elements[i] = INT_MAX;
	
	reps = repetidas(album, novas);
	
	for(k = 0; k < reps.n-1; k++)
	  printf("%d ", reps.elements[k]);
	printf("%d\n", reps.elements[k]);
	
	free(reps.elements);
	free(album.elements);
	free(novas.elements);
	
	return 0;
}