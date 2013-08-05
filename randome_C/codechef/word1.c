#include <stdio.h>

//Fast IO Section
#define MAX_BUFFER (512*1024)
char inBuffer[MAX_BUFFER];
int inBuffFilled = 0, inBuffCurrent = 0;

inline void
fillInBuffer ()
{
	inBuffFilled = fread (inBuffer, 1, MAX_BUFFER, stdin);
	inBuffCurrent = 0;
}

inline char
getNextChar ()
{
	if (inBuffCurrent >= inBuffFilled) {
		fillInBuffer ();
	}
	return inBuffer[inBuffCurrent++];
}

inline void
skipSpaces ()
{
	while (inBuffer[inBuffCurrent] == ' '
	       || inBuffer[inBuffCurrent] == '\n')
		inBuffCurrent++;
}

unsigned long
inReadNum ()
{
	long num = 0;
	skipSpaces ();
	char ch;
	while (1) {
		ch = getNextChar ();
		if (ch >= '0' && ch <= '9') {
			num = (num * 10) + (ch - '0');
		}
		else {
			return num;
		}
	}
}

unsigned int
inFirstLetter ()
{
	skipSpaces ();
	char ch = getNextChar ();
	return (ch - 'a');
}

unsigned int
inLastLetter ()
{
	char prev = getNextChar ();
	char curr = prev;
	do {
		prev = curr;
		curr = getNextChar ();
	}
	while (curr >= 'a' && curr <= 'z');
	return (prev - 'a');
}

//End of Fast IO Section

unsigned int edges[26][26];
unsigned int startCount[26], endCount[26], nodeFlag[26];


void
zeromap ()
{
	int i, j;
	for (i = 0; i < 26; i++) {
		startCount[i] = 0;
		endCount[i] = 0;
		nodeFlag[i] = 0;
		for (j = 0; j < 26; j++)
			edges[i][j] = 0;
	}
}

int
checkEulerConditions ()
{
	int i, j, orderVar;
	short int bStart = 0, bEnd = 0;
	int startCh = -1, endCh = -1;
	for (i = 0; i < 26; i++) {
		orderVar = startCount[i] - endCount[i];
		if (orderVar == 1) {
			if (bStart)
				return -1;
			bStart = 1;
			startCh = i;
			continue;
		}
		if (orderVar == -1) {
			if (bEnd)
				return -1;
			bEnd = 1;
			endCh = i;
			continue;
		}
		if (orderVar)
			return -1;
	}
	return 0;
}

void
NodeConnect (int node, int *visited)
{
	int i = 0;
	for (i = 0; i < 26; i++) {
		if (edges[node][i] || edges[i][node]) {
			if (!visited[i]) {
				visited[i] = 1;
				NodeConnect (i, visited);
			}
		}
	}
}

void
SolveEdgeMap ()
{
	int i, j;
	int startCh = checkEulerConditions ();
	int nodeCount = 0, visitedCount = 0;
	int visited[26];
	if (startCh != -1) {
		for (i = 0; i < 26; i++) {
			nodeCount += nodeFlag[i];
			visited[i] = 0;
		}
		i = 0;
		while (!nodeFlag[i] && i < 26)
			i++;
		visited[i] = 1;
		NodeConnect (i, visited);
		for (i = 0; i < 26; i++) {
			visitedCount += visited[i];
		}
		if (nodeCount == visitedCount) {
			printf ("Ordering is possible.\n");
			return;
		}
	}
	printf ("The door cannot be opened.\n");
}

int
main ()
{
	int nNumTestCases = 0;
	int nNumWords = 0;
	int i, j, first, last;
	nNumTestCases = inReadNum ();
	for (i = 0; i < nNumTestCases; i++) {
		zeromap ();
		nNumWords = inReadNum ();
		for (j = 0; j < nNumWords; j++) {
			first = inFirstLetter ();
			last = inLastLetter ();
			startCount[first]++;
			endCount[last]++;
			nodeFlag[first] = 1;
			nodeFlag[last] = 1;
			edges[first][last]++;
		}
		SolveEdgeMap ();
	}
	return 0;
}
