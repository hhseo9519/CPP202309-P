#include <cstdio>
#include <iostream>

using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end)//�־��� �������� ���� ���� ������ ��ġ�� ã�� �Լ�
{
	int index = begin;// �־��� ���������� ù��° �ε����� �����ϴ� ���� begin���� index������ �ʱ�ȭ ��ŵ�ϴ�.

	for (int i = begin; i <= end; i++)
	{
		/* data�迭���� data[i]�� data[index]���� �۴ٸ� index�� i�� �����մϴ�.
		�׷��� ��� �ݺ��ؼ� i�� end�� �������� ���ߴµ�
		�׷��� �ϸ� �־��� ���������� ���� ���� ������ �ε����� index������ ������ �� �ְ� �˴ϴ�.*/
		if (data[index] > data[i])
		
		{
			index = i;
		}
	}
	return index;//���� ����� ����� �־��� ���������� ���� ���� ������ ��ġ�� ����� index�� ���� ��ȯ�մϴ�.
}

void selectionSort(int data[], int n)
{
	for (int i = 0; i < n; i++) {
		int minIndex = getMinIndexInRange(data, n, i, n -1);//�־��� �������� ���� ���� ������ ��ġ�� ã���ϴ�

		//2���� ���ڰ� ����Ǿ� �ִ� ��ġ�� �����Ѵ� ��������� data[i]�� ���� �־��� ���������� ���� ���� ���Ұ� ����˴ϴ�.
		int num = data[minIndex];
		data[minIndex] = data[i];
		data[i] = num;
	}
}

int main() {
    int n; // ���� n�� �����Ͽ� �Է��� ������ ������ ������ ������ ����մϴ�.
    int* data; // �������� �Ҵ�� ���� �迭�� ����Ű�� ������ ���� data�� �����մϴ�.

    // ����ڷκ��� n�� ���� �Է¹޽��ϴ�.
    scanf("%d", &n);

    // ���̰� n�� ���� �迭�� �������� �Ҵ��Ͽ� data�� �Ҵ��մϴ�.
    data = new int[n];

    // ����ڷκ��� n���� ������ �Է¹޾� data �迭�� �����մϴ�.
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // ���� ����(selection sort) �˰����� ����Ͽ� data �迭�� �����մϴ�.
    selectionSort(data, n);

    // ���ĵ� data �迭�� ����մϴ�.
    for (int i = 0; i < n; i++) {
        // ��� ������ ���߱� ���� i�� 0���� ū ��� ������ ����մϴ�.
        if (i > 0) {
            printf(" ");
        }
        // data[i]�� ����մϴ�.
        printf("%d", data[i]);
    }

    // �������� �Ҵ�� �޸𸮸� ��ȯ�մϴ�.
    delete[] data;
    return 0;
}