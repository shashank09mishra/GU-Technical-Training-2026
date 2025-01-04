def reservedSeats(n, bookings):
    seats = [0] * n
    for booking in bookings:
        for i in range(booking[0], booking[1]+1):
            seats[i-1] += booking[2]
    return seats


# n = 5
# bookings = [[1, 2, 10], [2, 3, 20], [2, 5, 25]]
n=3
bookings=[[1,3,5],[2,2,10]]
res = reservedSeats(n, bookings)
print(res)
#output [10, 55, 45, 25, 25]
#Time Complexity = O(n*m) [n=no.of flights; m=booking range]
#Space Complexity =O(n)

