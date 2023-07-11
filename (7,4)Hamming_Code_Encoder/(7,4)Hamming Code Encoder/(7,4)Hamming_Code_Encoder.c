// (7,4) Hamming code Encoder
#include<stdio.h>
#include<string.h>

int main() {
	printf("Hamming ���ڴ� (�Է� 4-bit, ��� 7-bit)\n");
	while (1) {

		char input[5] = { 0 };
		int input_s[4] = { 0, };
		int output_t[7] = { 0, };
		int generator_matrix_G[7][4] = {
			//�������
			/*
			1000101
			0100111
			0010110
			0001011
			�� ��꿡 ���Ǽ��� ���� ���η� ������ �迭�� ����*/
			{1,0,0,0},	{0,1,0,0},	{0,0,1,0},
			{0,0,0,1},	{1,1,1,0},	{0,1,1,1},	{1,0,1,1}
		};
		char result[8] = { 0 };

		
		printf("�Է�: ");
		scanf("%s", input);

		for (int i = 0; input[i]; i++) {
			input_s[i] = input[i] - '0';
		}
		//�Էº�Ʈ�� ��������� ��Ŀ����� ���� 7��Ʈ�� ���ϴµ� �̶� ����ϴ� ������ modulo-2 ���� �������� ����Ѵ�.
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				if (generator_matrix_G[i][j] == 1)
				{
					output_t[i] ^= input_s[j];
				}
			}
		}

		/*
		////////////////////�׽�Ʈ ���//////////////////////////
		char result_for_test[9] = { 0 };//���� �ϳ� ����
		sprintf(result_for_test, "%d%d%d%d %d%d%d", output_t[0], output_t[1], output_t[2], output_t[3], output_t[4], output_t[5], output_t[6]);
		printf("���(���� ���� �׽�Ʈ��): %s\n", result_for_test);
		*/

		sprintf(result, "%d%d%d%d%d%d%d", output_t[0], output_t[1], output_t[2], output_t[3], output_t[4], output_t[5], output_t[6]);
		printf("���: %s\n", result);

	}
	
	return 0;
}