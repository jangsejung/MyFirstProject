재귀함수의 기본으로 알아두자 
하나를 실행하고 바로 아래로 내려가는것이 아니라 그 하나가 실행이 끝나야 다음것으로 넘어감
예를 들어 하노이탑처럼

        Hanoi(n-1, from, temp, to);
        printf("Disk %d : Move %c to %c\n", n, from, to);
        Hanoi(n-1, from, temp, to);

라는 문장이 있을 경우(위 문장은 n이 1이 아닐경우다)
n에 3이 들어간고 가정하자 그렇다면 결국
        Hanoi(2, from, temp, to);
        printf("Disk %d : Move %c to %c\n", n, from, to);
        Hanoi(2, from, temp, to);
라는 값이 만들어지며 이 값은 바로 실행이 되는것이 아닌 또 n이 2일경우의 코드 진행이가고
결국 if (n == 1)
    {
        printf("Disk %d : Move %c to %c\n", n, from, to);
    }
라는 실행을 찍고 다음 값으로 순차적으로 다시 올라간다
즉 n이 3일경우 Hanoi(2) -> Hanoi(1) -> (1)출력 -> (2)일때의 printf 출력 -> (1)출력 후 3을 출력하는 것이다
따라서 실행 결과를 보면
Disk 1 -> 2 -> 1 ->3 -> 1 -> 2 -> 1 의 규칙을 볼 수 있다.

패턴을 조금 더 분석해보면
1 ~ (n-1) : A -> B
n : A - > C
1 ~ (n-1) : B -> C 같은 느낌?