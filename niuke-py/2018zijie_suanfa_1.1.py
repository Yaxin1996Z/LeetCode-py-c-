def findMaxSubset(data_size, data):
    data.sort()
    y = 0
    res =[]
    for point in reversed(data):
        if point[1] >= y:
            res.append(point)
        y = max(y, point[1])
    return res

# input
# data_size = input()
# data = []
# for i in range(int(data_size)):
#     x, y = map(int, input().split())
#     data.append([x,y])
#
# for x, y in reversed( findMaxSubset(data_size, data)):
#     print(x, y)

def test():
    data_size = 5
    data=[
    [1, 2],
    [5, 3],
    [7, 5],
    [4, 6],
    [9, 0]]

    for x, y in reversed( findMaxSubset(data_size, data)):
        print(x, y)

test()
