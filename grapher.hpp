//
// Created by protobit on 02/10/2020.
//

#ifndef EPISIM_GRAPHER_HPP
#define EPISIM_GRAPHER_HPP

#include <SDL.h>
#include <string>
#include <vector>
#include <cmath>
#include "fstream"
template<typename T, int multiplier, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class grapher_template {
public:
    grapher_template(int size, std::string name, int max_y, int y,int x_step,bool write_to_file) {
        _size = size;
        _name = name;
        _max_Y = max_y;
        _y = y;
        _x_step = x_step;
        _w = write_to_file;
        window = SDL_CreateWindow(name.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,size*_x_step,y,0);
        rend = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        data.resize(_size);
        SDL_SetRenderDrawColor(rend,255,255,255,255);
        file.open("./"+_name+".csv",std::ios::out);
        if (file.is_open()) {
            file << _name << "\n";
        }
    }
    void update() {
        if (data[data.size()-1]*multiplier > _max_Y) {
            _max_Y = data[data.size()-1]*multiplier;
        }
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend,255,255,255,255);
        for (int i = 1; i < data.size(); i++) {
            SDL_RenderDrawLine(rend,(i-1)*_x_step,ilerp(0.0f,_y,_max_Y-(data[_size-i+1]*multiplier),_max_Y),i*_x_step,ilerp(0.0f,_y,_max_Y-(data[_size-i]*multiplier),_max_Y));
        }
        SDL_RenderPresent(rend);
    }
    void append(T val) {
        if (data.size() == _size) {
            data.erase(data.cbegin());
        }
        data.emplace_back(val);
        count++;
        file << std::to_string(count) << "," << std::to_string(val) << "\n";
    }

    void closeGraph() {
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
        file.flush();
        file.close();
    }

    ~grapher_template() {
        closeGraph();
    }
private:
    int ilerp (int a, int b, int t, int max_t) {
        float ft = t;
        float fmt = max_t;
        return a + ((ft / fmt) * (b-a));
    }
    int _size;
    std::string _name;
    int _max_Y;
    int _y;
    int _x_step;
    bool _w;
    int count;
    std::ofstream file;
    SDL_Renderer* rend;
    SDL_Window* window;
    std::vector<T> data;
};

typedef grapher_template<int,1> grapher;

#endif //EPISIM_GRAPHER_HPP
