//17478 ����Լ��� ������?
#include <stdio.h>
void solve(int a, int N){
    if(a == 0)
        printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    
    if(a == N){
    for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("\"����Լ��� ������?\"\n");
     for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
     for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("��� �亯�Ͽ���.\n");
        return;
    }


    for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("\"����Լ��� ������?\"\n");

    for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
    
    for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
    
    for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");


    solve(a+1, N);
    for(int i = 0; i < 4 * a; i++){
        printf("_");
    }
    printf("��� �亯�Ͽ���.\n");
}

int main(){
    int N;
    scanf("%d", &N);
    solve(0, N);
    return 0;
}