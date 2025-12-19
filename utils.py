# Left → first place x could go (first occurance)
def bisect_left(arr, search):
    lft, rght = 0, len(arr)

    while lft < rght:
        mid = (lft + rght) // 2

        if arr[mid] < search:
            lft = mid + 1
        else:
            rght = mid

    return lft


# Right → first place x could not go (last occurance + 1)
def bisect_right(arr, search):
    lft, rght = 0, len(arr)

    while lft < rght:
        mid = (lft + rght) // 2

        if arr[mid] <= search:
            lft = mid + 1
        else:
            rght = mid

    return lft


def insert(arr, idx, val):
    arr.append(0)
    for i in range(len(arr) - 1, idx, -1):
        arr[i] = arr[i - 1]
    arr[idx] = val

