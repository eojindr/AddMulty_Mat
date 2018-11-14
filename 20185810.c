#include <stdio.h>

int indexAddMat(int a, int b) {
	return a + b;
}

int ptrProdMat_1(int (*a)[3], int (*b)[3]) {
	static int i = 0, j = 0, k = 0, l = 0;
	int x = 0, y = 0;
	x = *(a[i] + j);
	y = *(b[k] + l);
	if (j == 2) {
		j = -1;
		k = -1;
		if (l == 2) {
			l = -1;
			i++;
		}
		l++;
	}
	j++;
	k++;
	
	return  x * y;
}

int ptrProdMat_2(int a, int b, int c) {
	int sum = a + b + c;
	return sum;
}

int main() {
	int n;
	int insert1[3][3];
	int insert2[3][3];
	int add12[3][3];
	int mul12_1[3][3][3];
	int mul12_2[3][3];

	printf("1번째 값을 입력해주세요.\n");
	for (int i = 0; i < 3; i++) {
			scanf("%d %d %d", &insert1[i][0], &insert1[i][1], &insert1[i][2]);
	}

	printf("2번째 값을 입력하실려면 1을 1번째와 같은 값으로 하시려면 0을 입력해주세요.\n");
	scanf_s("%d", &n);
	if (n == 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				insert2[i][j] = insert1[i][j];
			}
		}
	}
	else{
		for (int i = 0; i < 3; i++) {
			scanf("%d %d %d", &insert2[i][0], &insert2[i][1], &insert2[i][2]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			add12[i][j] = indexAddMat(insert1[i][j], insert2[i][j]);
		}
	}

	int(*insert_1)[3] = insert1;
	int(*insert_2)[3] = insert2;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				mul12_1[i][j][k] = ptrProdMat_1(insert_1, insert_2);
			}
		}
	}		
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
				mul12_2[i][j]= ptrProdMat_2(mul12_1[i][j][0], mul12_1[i][j][1], mul12_1[i][j][2]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d	", insert1[i][j]);
		}
		if (i == 1)
			printf("+	");
		else
			printf("	");
		for (int j = 0; j < 3; j++) {
			printf("%d	", insert2[i][j]);
		}
		if (i == 1)
			printf("=	");
		else
			printf("	");
		for (int j = 0; j < 3; j++) {
			printf("%d	", add12[i][j]);
		}
		puts("");
	}
	puts("");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d	", insert1[i][j]);
		}
		if (i == 1)
			printf("*	");
		else
			printf("	");
		for (int j = 0; j < 3; j++) {
			printf("%d	", insert2[i][j]);
		}
		if (i == 1)
			printf("=	");
		else
			printf("	");
		for (int j = 0; j < 3; j++) {
			printf("%d	", mul12_2[i][j]);
		}
		puts("");
	}

	system("pause");
	return 0;
}
