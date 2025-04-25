#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <execution> 
struct Point3D {
    float x, y, z;
    float vx, vy, vz;
    float mass;
    float potential;
};

bool compareEnergy(const std::pair<int, float>& a, const std::pair<int, float>& b) {
    return a.second < b.second;
}

int main() {
    const int numPoints = 1000000; // 一千万个粒子
    std::vector<Point3D> points(numPoints);

    // 初始化随机数生成器
    std::srand(static_cast<unsigned int>(std::time(0)));

    // 生成随机粒子数据
    for (int i = 0; i < numPoints; ++i) {
        points[i].x = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].y = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].z = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].vx = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].vy = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].vz = static_cast<float>(std::rand()) / RAND_MAX * 20 - 10;
        points[i].mass = static_cast<float>(std::rand()) / RAND_MAX * 10;
        points[i].potential = -static_cast<float>(std::rand()) / RAND_MAX * 10;
    }

    // 计算每个粒子的总能量
    std::vector<std::pair<int, float>> energies;
    energies.reserve(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        float kineticEnergy = 0.5f * points[i].mass * (points[i].vx * points[i].vx + points[i].vy * points[i].vy + points[i].vz * points[i].vz);
        float totalEnergy = kineticEnergy + points[i].potential;
        energies.push_back(std::make_pair(i, totalEnergy));
    }

    // 测量排序时间
    std::clock_t start = std::clock();
    std::sort(std::execution::par, energies.begin(), energies.end(), compareEnergy);
    std::clock_t end = std::clock();

    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Sorting time: " << elapsed_secs << " seconds" << std::endl;

    return 0;
}