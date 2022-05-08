int mypow(int a, int b)
{
    int res;
    if (b == 0) {
        return 1;
    }
    a = a % 10007;
    if (b % 2 == 1) { // ����
        res = (a * mypow(a, b - 1)) % 10007;
    } else {          // ż��
        int sub = mypow(a, b / 2);
        res = (sub * sub) % 10007;
    }
    return res;
}
int solve(int a, int *b, int bSize)
{
    if (bSize == 0) {   //b����ĳ��� 
        return 1;
    }
    int part1 = mypow(a, b[bSize - 1]);   //�ȼ������������һ����������[1,4,6,4]�е��±�Ϊ3��4 
    int part2 = mypow(solve(a, b, bSize - 1), 10);   //���еݹ飬��4��ȡ�����������Ϊ[1,4,6,0]��Ȼ��0תΪ������[1,4,6]�η���10�Σ��ټ������еݹ顣 
    return (part1 * part2) % 10007;
}
