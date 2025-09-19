import random
import math
import matplotlib.pyplot as plt
import sys


def generate_convex_polygon_simple(n, width=100, height=100):
    points = []
    for i in range(n):
        points.append((random.uniform(0, width), random.uniform(0, height)))
    
    center_x = sum(p[0] for p in points) / n
    center_y = sum(p[1] for p in points) / n
    
    points.sort(key=lambda p: math.atan2(p[1]-center_y, p[0]-center_x))
    
    return points

def plot_polygon(points):
    x, y = zip(*points)
    
    plt.figure(figsize=(8, 8))
    plt.plot(x + (x[0],), y + (y[0],), 'b-', linewidth=2)
    plt.scatter(x, y, color='red', s=50)
    plt.title("Polygon")
    plt.grid(True)
    plt.axis('equal')
    plt.show()


N = 30
if len(sys.argv) > 1:
    N = int(sys.argv[1])

polygon = generate_convex_polygon_simple(N)

print(N)
for pair in polygon:
    print(pair[0], pair[1], end='  ')

if N <= 30:
    plot_polygon(polygon)