// (7,4) Hamming code Encoder
#include<stdio.h>
#include<string.h>

int main() {
	printf("Hamming 인코더 (입력 4-bit, 출력 7-bit)\n");
	while (1) {

		char input[5] = { 0 };
		int input_s[4] = { 0, };
		int output_t[7] = { 0, };
		int generator_matrix_G[7][4] = {
			//생성행렬
			/*
			1000101
			0100111
			0010110
			0001011
			를 계산에 편의성을 위해 세로로 나누어 배열에 저장*/
			{1,0,0,0},	{0,1,0,0},	{0,0,1,0},
			{0,0,0,1},	{1,1,1,0},	{0,1,1,1},	{1,0,1,1}
		};
		char result[8] = { 0 };

		
		printf("입력: ");
		scanf("%s", input);

		for (int i = 0; input[i]; i++) {
			input_s[i] = input[i] - '0';
		}
		//입력비트와 생성행렬을 행렬연산을 통해 7비트를 구하는데 이때 사용하는 덧셈은 modulo-2 덧셈 연산으로 계산한다.
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				if (generator_matrix_G[i][j] == 1)
				{
					output_t[i] ^= input_s[j];
				}
			}
		}

		/*
		////////////////////테스트 출력//////////////////////////
		char result_for_test[9] = { 0 };//공백 하나 포함
		sprintf(result_for_test, "%d%d%d%d %d%d%d", output_t[0], output_t[1], output_t[2], output_t[3], output_t[4], output_t[5], output_t[6]);
		printf("출력(공백 포함 테스트용): %s\n", result_for_test);
		*/

		sprintf(result, "%d%d%d%d%d%d%d", output_t[0], output_t[1], output_t[2], output_t[3], output_t[4], output_t[5], output_t[6]);
		printf("출력: %s\n", result);

	}
	
	return 0;
}