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
    if ((*(Point*)pointA).x  > (*(Point*)pointB).x) {
        return 1;
    } else if ((*(Point*)pointA).x  < (*(Point*)pointB).x) {
        return -1;
    } else {
        return 0;
    }
    // return (*(Point*)pointA).x - (*(Point*)pointB).x > 0 ? 1 : -1;
}

// 计算两个点之间的距离平方
float calculatePointDistance(Point pointA, Point pointB) {
    return sqrt((pointA.x - pointB.x) * (pointA.x - pointB.x) + (pointA.y - pointB.y) * (pointA.y - pointB.y));
}

// 计算点之间最小距离
float calculateMinDistance (Point points[], int start, int end) {
    if (end == start) {  // 1个点
        return 0.0F;
    } else if (end - start == 1) { // 2个点
        return calculatePointDistance(points[start], points[end]); 
    } else if (end - start == 2) { // 3个点
        float distance12 = calculatePointDistance(points[start], points[start + 1]);
        float distance13 = calculatePointDistance(points[start], points[end]);
        float distance23 = calculatePointDistance(points[start + 1], points[end]);
        float minDistance = distance12;

        if (minDistance > distance23) {
            minDistance = distance23;
        } 

        if (minDistance > distance13) {
            minDistance = distance13;
        }

        return minDistance;
    } else { // 多点时

        // 现在超时，还需优化。
        int middle = (start + end) / 2;
        float leftMin = calculateMinDistance(points, start, middle);
        float rightMin = calculateMinDistance(points, middle + 1, end);

        // printf("LeftMin %0.2f ----- RightMin %0.2f\n", leftMin, rightMin);


        // 获取两侧最小距离
        float minDistance = leftMin > rightMin ? rightMin : leftMin;
        float leftX = points[middle].x - minDistance;
        float rightX = points[middle].x + minDistance;
        int interval = end - start;
        int counter = 0;

        for (int i = start; i <= middle; i++) {
            if (points[i].x < leftX) {
                continue;
            }


            for (int j = 1; j <= interval; j++) {
                if (i + j <= middle) {
                    continue;
                } 

                if (points[i + j].x > rightX) {
                    break;
                }

                float distance = calculatePointDistance(points[i], points[i + j]);
                // printf("PintA （%0.2f, %0.2f）--- PintB （%0.2f, %0.2f）\n", points[i].x, points[i].y, points[j].x, points[j].y);
                // printf("distance %0.2f\n", distance);
                if (distance < minDistance) {
                    minDistance = distance;
                }
            }
        }

        // printf("Min %0.2f\n", minDistance);
        return minDistance;
    }
}

// 杭电1007：获取最大环半径
float getLargestRadius(Point points[], int len) {
    qsort(points, len, sizeof(Point), comp);
    return calculateMinDistance(points, 0, len - 1) / 2;
}

int main() {

    Point points[100000];
     int n,i;

     while(scanf("%d",&n) != EOF && n != 0) {

          for(i=0; i < n; i++) {
              scanf("%f%f",&points[i].x,&points[i].y);
          }
   
        float r = getLargestRadius(points, n);
        printf("%0.2f\n", r);

    }

    return 0;
}



