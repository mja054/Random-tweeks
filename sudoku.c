#include<stdio.h>

int m;
int n;
int p;
int q;

int ref [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int mat[9][9] = { 
		  {8, 7, 0, 2, 3, 1, 4, 0, 0},
		  {5, 0, 0, 8, 0, 6, 3, 0, 1},
		  {3, 1, 0, 4, 5, 7, 6, 8, 2},
		  {4, 0, 5, 6, 1, 0, 0, 0, 8},
		  {0, 9, 1, 0, 2, 0, 0, 4, 0},
		  {2, 0, 8, 7, 5, 5, 0, 0, 3},
		  {1, 5, 0, 9, 0, 3, 2, 6, 7},
		  {6, 0, 3, 1, 7, 4, 8, 0, 5},
		  {9, 0, 7, 0, 6, 0, 1, 0, 4}
		};

int row_elements [9][9];

int
fill_row_elements()
{
	int i,j;

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if ( mat[i][j] != 0)
				row_elements [i][mat [i][j] - 1] = 1;

	for (i = 0; i < 9; i++){
                for (j = 0; j < 9; j++)
                	printf ("%d ",row_elements [i][j]);
		printf ("\n");
	}
	printf ("\n");
	printf ("\n");
	return 0;
}

int 
assign_box (int a, int b, int c, int d)
{
	m = a;
	n = b;
	p = c;
	q = d;

//	printf ("%d %d %d %d", m, n, p, q);

	return 0;
}

int
find_box (int i, int j)
{
  	if (i >= 0 && i <= 2)
		if (j >= 0 && j <= 2){
			assign_box (0, 0, 2, 2);
		}

	else if (i >= 0 && i <= 2)
                if (j >= 3 && j <= 5)
                        assign_box (0, 3, 2, 5);

	else if (i >= 0 && i <= 2)
                if (j >= 6 && j <= 8)
                        assign_box (0, 6, 2, 8);

	else if (i >= 3 && i <= 5)
                if (j >= 0 && j <= 2)
                        assign_box (3, 0, 5, 2);

	else if (i >= 3 && i <= 5)
                if (j >= 3 && j <= 5)
                        assign_box (3, 3, 5, 5);

	else if (i >= 3 && i <= 5)
                if (j >= 6 && j <= 8)
                        assign_box (3, 6, 5, 8);

	else if (i >= 6 && i <= 8)
                if (j >= 0 && j <= 2)
                        assign_box (6, 0, 8, 2);

	else if (i >= 6 && i <= 8)
                if (j >= 3 && j <= 5)
                        assign_box (6, 3, 8, 5);

	else 
                assign_box (6, 6, 8, 8);

	return 0;
}

//finding an element that is to be tested
int
find_ele_from_row (int i, int cn)
{
	int j;

	for (j=cn; j<9; j++)
		if ( row_elements [i][j] == 0)
	//		row_elements [i][j] = 1;
			return j+1;
	return -1; 
}

//now test that element against that column
int
test_element_in_col (int j, int ele)
{
	int i;
	
	for (i=0; i<9; i++)
		if (mat [i][j] == ele)
			return -1;
	return 0;
}

//now test that element against in its box
int
test_element_in_box (int i, int j, int ele)
{
	int a, b;

	
	find_box (i, j);

//	printf ("%d %d %d %d", m,p,n,q);
	for (a = m; a <= p; a++)
		for (b = n; b <= q; q++)
			if (mat [a][b] == ele) 
				return -1;
	return 0;

}				

//find empty space in matrix	
int 
test_empty_space (int i)
{
	int j;
	
	for (j = 0; j < 9; j++)
		if ( mat [i][j] == 0)
			return j;
	return -1;
}

int
find_empty_space()
{
	int i, j, k, ele, ret, temp;

	printf ("start");
	for (i = 0; i < 9; i++){
		if ( ( j=test_empty_space (i)) != -1)
			break;
	}


	if (i == 9)
		return 0;
	else{
	    for (k = mat [i][j]; k < 9; ){  
		ele = find_ele_from_row (i, k);
		printf ("(%d,%d)%d ", i, j, ele);

		if (ele == -1)
			break;

		if (ele > k )
			k = ele;
		else
			k++;

		for (temp = 0; temp < 10000000; temp++) ;

		if (test_element_in_col (j, ele) == 0){
			printf ("success in col ");
			if (test_element_in_box (i, j, ele) == 0){
				printf ("success in box\n");
				mat [i][j] = ele;
				row_elements [i][ele - 1] = 1;
				ret = find_empty_space ();
				if (ret == 0)
					return 0;
				row_elements [i][ele - 1] = 0;
			}
		}
	    }
	    mat [i][j] = 0;	
	    return -1;
	}

}

int
print_sudoku()
{
	int i, j, temp;

	printf ("\n");
	printf ("\n");
	
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			printf ("%d ", mat [i][j]);
			for (temp = 0; temp < 10000000; temp++) ;
		}
		printf ("\n");
	}
	return 0;
}

int 
main (int argc, char *argv[])
{
//	find_box (2, 7);
	fill_row_elements();

	print_sudoku ();
	find_empty_space ();
	print_sudoku ();
	return 0;
}
