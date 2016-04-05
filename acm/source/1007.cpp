#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 点
struct Point {
	float x;
	float y;
};


// 点排序
int comp(const void* pointA, const void* pointB) {
	return (*(Point*)pointA).x - (*(Point*)pointB).x > 0 ? 1 : -1;
}

// 计算两个点之间的距离平方
float calculatePointDistance(Point pointA, Point pointB) {
	return sqrt((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y));
}

// 计算点之间最小距离
float calculateMinDistance (Point points[], int start, int end) {
	if (end <= start) {  // 1个点

		printf("%s\n", "end == start");
		return 0.00f;
	} else if (end - start == 1) { // 
		printf("%s\n", "2 points");
		return calculatePointDistance(points[start], points[end]);
	} else {
		printf("%s\n", "> 2 points");
		int middle = (start + end) / 2;
		float leftMin = calculateMinDistance(points, start, middle);
		float rightMin = calculateMinDistance(points, middle + 1, end);

		// 获取两侧最小距离
		float minDistance = leftMin > rightMin ? rightMin : leftMin;
		float leftX = points[middle].x - minDistance;
		float rightX = points[middle].x + minDistance;
		int interval = end - start;

		for (int i = start; i <= end; i++) {
			if (points[i].x < leftX) {
				continue;
			}

			if (points[i].x > points[middle].x) {
				break;
			}

			for (int j = 1; j <= interval; j++) {
				if (points[i + j].x < leftX) {
					continue;
				}

				if (points[i + j].x > rightX) {
					break;
				}

				float distance = calculatePointDistance(points[i], points[j]);
				if (distance < minDistance) {
					minDistance = distance;
				}
			}
		}

		return minDistance;
	}
}

int main() {
	// struct Point point;

	// point.x = 5.0F;
	// point.y = 6.0F;

	// printf("%0.2f\n", point.x);
	Point point1 = {2, 3};
	Point point2 = {8, 9};
	Point point3 = {6, 3};
	Point point4 = {6, 9};


	Point points[4] = {point1, point2, point3, point4};

	// qsort(points, 3, sizeof(points[0]), comp);

	// for (int i = 0; i < 3; i++) {
	// 	printf("%0.2f\n", points[i].x);
	// }

    float r = calculateMinDistance(points, 0, 3);
    printf("%0.2f\n", r);

	return 0;
}





