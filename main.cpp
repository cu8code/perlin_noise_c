#include <math.h>
#include <iostream>
#include "perlin.hpp"
#include <random>
#include <ctime>

#define N_W 100
#define N_H 100

int main(){
  std::srand(std::time(0));
  const siv::PerlinNoise::seed_type seed = std::rand();
  const siv::PerlinNoise perlin { seed };
  float m[N_W][N_H] = {0};

  for(int x=0; x < N_W;++x){
    for(int y=0; y < N_H;++y){
        const float noise = perlin.octave2D_01((x * 0.01), (y * 0.01), 4);
        m[x][y] = noise;
        // std::cout << noise;
    }
  }

  std::cout << "\n";

  for(int x=0; x < N_W;++x){
    for(int y=0; y < N_H;++y){
        const float n = m[x][y];
        if(0<n && n<0.5){
          std::cout << "~";
        }else if(0.5<n && n <0.55){
          std::cout << "S";
        }else if(0.55<n && n <0.65){
          std::cout << "$";
        }else if(0.65<n && n <0.7){
          std::cout << "h";
        }else if(0.7<n && n <1){
          std::cout << "M";
        }

    }
    std::cout << "\n";
  }
  return 1;
}
