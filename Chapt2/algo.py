import math

# 全局变量收集递归中间结果
res = []


def find_equation(array, sum, temp=''):
    """
    递归搜索和数
    :param array: 当前栈
    :param sum: 需要满足的和
    :param temp: 中间栈
    """

    # 栈空退出当前递归
    if len(array) == 0:
        return

    # 栈顶元素满足条件
    if array[0] == sum:
        equ = temp + str(array[0])
        res.append(equ)

    # 检验即将出栈的元素是否符合条件
    find_equation(array[1:], sum, temp)

    # 元素出栈
    find_equation(array[1:], sum - array[0], str(array[0]) + '+' + temp)


def inversion_number(array):
    """
    计算向量的逆序数
    :param array: 向量
    :return: 逆序数
    """
    sum = 0

    # 两层循环，遍历对称矩阵
    for i in range(len(array) - 1):
        for j in range(i + 1, len(array)):

            # 判断大小并计数
            if array[i] > array[j]:
                sum += 1
    return sum


def chess(a, b, aa, bb, length, t):
    if length == 1:
        return
    t += 1
    tem = t
    l = length // 2
    if aa < a + l and bb < b + l:
        chess(a, b, aa, bb, l, t)
    else:
        A[a + l - 1][b + l - 1] = tem
        chess(a, b, a + l - 1, b + l - 1, l, t)

    if aa >= a + l and bb < b + l:
        chess(a + l, b, aa, bb, l, t)
    else:
        A[a + l][b + l - 1] = tem
        chess(a + l, b, a + l, b + l - 1, l, t)

    if aa < a + l and bb >= b + l:
        chess(a, b + l, aa, bb, l, t)
    else:
        A[a + l - 1][b + l] = tem
        chess(a, b + l, a + l - 1, b + l, l, t)

    if aa >= a + l and bb >= b + l:
        chess(a + l, b + l, aa, bb, l, t)
    else:
        A[a + l][b + l] = tem
        chess(a + l, b + l, a + l, b + l, l, t)


def test1():
    A = [2, 1, 3, 4, 5, 6, 7, 8, 9]
    s = 14
    find_equation(A, s)
    print('result:', res)
    print('length:', len(res))


def test2():
    A = [2, 4, 1, 3, 5]
    B = [3, 4, 1, 5, 2]
    A_inversion_number = inversion_number(A)
    print('A: ', A_inversion_number)

    B_inversion_number = inversion_number(B)
    print('B: ', B_inversion_number)

    if A_inversion_number < B_inversion_number:
        print('读者A更适合用户')
    else:
        print('读者B更适合用户')

def maximumGap(nums):
    if len(nums) < 2:
        return 0

    # O(n)
    max_val, min_val = max(nums), min(nums)
    if max_val == min_val:
        return 0

    n = len(nums)
    size = (max_val - min_val) / (n - 1)

    # 构造桶 O(n)
    bucket = [[None, None] for _ in range(n + 1)]

    # 生成桶 O(n)
    for num in nums:
        b = bucket[math.floor((num - min_val) // size)]
        b[0] = min(b[0], num) if b[0] else num
        b[1] = max(b[1], num) if b[1] else num

    # 排除空桶 O(n)
    bucket = [b for b in bucket if b[0] is not None]
    print('bucket: ', bucket)

    # 计算相邻桶的gap O(n)
    return max(bucket[i][0] - bucket[i - 1][1] for i in range(1, len(bucket)))


def test3():
    array = [2.3, 3.1, 7.5, 1.5, 6.3]

    gap = maximumGap(array)
    print('GAP: ', round(gap, 2))


def test4():
    n = int(math.pow(2, 3))
    global A
    A = [[0 for _ in range(0, n)] for _ in range(0, n)]
    print('输入特殊点行号aa：')
    aa = int(input())
    print('输入特殊点列号bb：')
    bb = int(input())
    a = b = 1
    t = 0
    chess(a, b, aa, bb, n, t)
    for i in range(0, len(A)):
        print(A[i])


if __name__ == '__main__':
    # test1()

    # test2()

    # test3()

    test4()
