int mypow(int a, int b)
{
    int res;
    if (b == 0) {
        return 1;
    }
    a = a % 10007;
    if (b % 2 == 1) { // 奇数
        res = (a * mypow(a, b - 1)) % 10007;
    } else {          // 偶数
        int sub = mypow(a, b / 2);
        res = (sub * sub) % 10007;
    }
    return res;
}
int solve(int a, int *b, int bSize)
{
    if (bSize == 0) {   //b数组的长度 
        return 1;
    }
    int part1 = mypow(a, b[bSize - 1]);   //先计算数组中最后一个数，比如[1,4,6,4]中的下标为3的4 
    int part2 = mypow(solve(a, b, bSize - 1), 10);   //进行递归，将4提取出来后数组变为[1,4,6,0]，然后将0转为底数的[1,4,6]次方的10次，再继续进行递归。 
    return (part1 * part2) % 10007;
}
