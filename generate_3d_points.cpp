#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

struct Point3D {
    float x, y, z;
    float vx, vy, vz; // 速度分量
    float mass;      // 质量
    float potential; // 引力势
};

// 比较函数，用于按能量排序
bool compareEnergy(const std::pair<int, float>& a, const std::pair<int, float>& b) {
    return a.second < b.second;
}

int main() {
    const int numPoints = 5000;
    Point3D points[numPoints];

    // 初始化随机数生成器
    std::srand(static_cast<unsigned int>(std::time(0)));

    // 生成随机三维坐标点和速度，范围从 -10 到 10
    for (int i = 0; i < numPoints; ++i) {
        points[i].x = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].y = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].z = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].vx = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].vy = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].vz = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].mass = static_cast<float>(std::rand()) / RAND_MAX * 10; // 质量范围从 0 到 10
        points[i].potential = -static_cast<float>(std::rand()) / RAND_MAX * 10; // 引力势范围从 -10 到 0
    }

    // 计算每个粒子的总能量（动能 + 引力势能）
    std::vector<std::pair<int, float>> energies;
    for (int i = 0; i < numPoints; ++i) {
        float kineticEnergy = 0.5f * points[i].mass * (points[i].vx * points[i].vx + points[i].vy * points[i].vy + points[i].vz * points[i].vz);
        float totalEnergy = kineticEnergy + points[i].potential;
        energies.push_back(std::make_pair(i, totalEnergy));
    }

    // 按能量排序
    std::sort(energies.begin(), energies.end(), compareEnergy);

    // 计算能量最低的一百个粒子的平均速度和位置
    float avgX = 0, avgY = 0, avgZ = 0;
    float avgVx = 0, avgVy = 0, avgVz = 0;
    for (int i = 0; i < 100; ++i) {
        int index = energies[i].first;
        avgX += points[index].x;
        avgY += points[index].y;
        avgZ += points[index].z;
        avgVx += points[index].vx;
        avgVy += points[index].vy;
        avgVz += points[index].vz;
    }
    avgX /= 100;
    avgY /= 100;
    avgZ /= 100;
    avgVx /= 100;
    avgVy /= 100;
    avgVz /= 100;

    std::cout << "Average position of the lowest 100 energy particles: (" << avgX << ", " << avgY << ", " << avgZ << ")" << std::endl;
    std::cout << "Average velocity of the lowest 100 energy particles: (" << avgVx << ", " << avgVy << ", " << avgVz << ")" << std::endl;

    // 将点和速度写入文件
    std::ofstream outFile("3d_points_with_velocity.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < numPoints; ++i) {
            outFile << points[i].x << " " << points[i].y << " " << points[i].z << " "
                    << points[i].vx << " " << points[i].vy << " " << points[i].vz << "\n";
        }
        outFile.close();
        std::cout << "3D points with velocity have been written to 3d_points_with_velocity.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }

    return 0;
}