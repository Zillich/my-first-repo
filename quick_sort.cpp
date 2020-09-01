#include <stdio.h>

typedef struct stack_data{
	int r;
	int l;
	struct stack_data* next;
}stack_data;

// no recursion
void quick_sort(int* arr, int left, int right) {
	stack_data* s = malloc(sizeof(stack_data));
	s->r = right;
	s->l = left;
	s->next = NULL;

	stack_data* sp = s;
	while (sp != NULL) {
		// one time for quick_soft
		int i = sp->l;
		int j = sp->r;
		if (i < j) {
			int key = arr[sp->l];
			while (i < j) {
				while (i < j && key <= arr[j])
					j--;
				arr[i] = arr[j];
				while (i < j && key >= arr[i])
					i++;
				arr[j] = arr[i];
			}
			arr[i] = key;

			stack_data* right_data = malloc(sizeof(stack_data));
			stack_data* left_data = malloc(sizeof(stack_data));
			right_data->r = sp->r;
			right_data->l = i + 1;
			right_data->next = sp->next;
			left_data->r = i;
			left_data->l = sp->l;
			left_data->next = right_data;

			sp->next = left_data;
		}
		sp = sp->next;
		free(s);
		s = sp;
	}
}

int main(void){
	int arr[] = { 3, 5, 1, 2, 4 };
	int nun_arr = 5;
	quick_sort(arr, 0, nun_arr - 1);
	return 0;
}
