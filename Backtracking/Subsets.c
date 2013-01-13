#include<stdio.h>;

typedef int data;

int MAXCANDIDATES = 100;

int finished = 0;

int is_a_solution(int a[], int k, data input) {
    return (k == input);
}

void process_solution(int a[], int k, data input) {
    int i;

    printf("{");
    for (i = 1; i <= k; i++) {
        if (a[i] == 1) { 
            printf("%d", i);
        }
    }
    printf("}\n");
}

void construct_candidates(int a[], int k, data input, int c[], int *ncandidates) {
    c[0] = 1;
    c[1] = 0;
    *ncandidates = 2;
}

void make_move(int a[], int k, data input) {

}

void unmake_move(int a[], int k, data input) {
}

/**
 * If you remember one thing, remember this template
 */
void backtrack(int a[], int k, data input) {
    int c[MAXCANDIDATES];   // candidates for the next position
    int ncandidates;        // next position candidate count
    int i;

    if (is_a_solution(a, k, input)) {
        process_solution(a, k, input);
    } else {
        k = k + 1;
        construct_candidates(a, k, input, c, &ncandidates);
        for (i=0; i < ncandidates; i++) {
            a[k] = c[i];
            make_move(a, k, input);
            backtrack(a, k, input);
            unmake_move(a, k, input);
            if (finished) return;
        }
    }
}

int main(char *args[]) {
    int a[3];
    backtrack(a, 0, 3);
}
