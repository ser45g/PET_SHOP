#pragma once
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include "ID.cpp"

class uploader {
private:

    std::string _path;
public:
    uploader(const std::string& path) :_path(path) {}
    std::string get_path()const noexcept { return _path; }

    virtual bool upload(const std::vector<std::string>& cont) const noexcept = 0;
};

class text_uploader : public uploader {
private:
public:
    //text_uploader(const std::str){}
    using uploader::uploader;
    bool upload(const std::vector<std::string>& cont) const noexcept override {
        std::ofstream out(uploader::get_path());
        if (out.good()) {
            for (auto& el : cont) {
                out << el;
            }
            return true;
        }
        return false;
    }
};

template <typename T>
class downloader {
private:
    std::string _path;
public:
    downloader(const std::string& path) :_path(path) {}
    std::string get_path()const noexcept { return _path; }
    virtual std::list<T*> load() const noexcept = 0;
};

template <typename T, typename Factory >
class text_downloader :public downloader<T> {
private:
    Factory* _factory;
public:
    text_downloader(const std::string& path, Factory* factory) : downloader<T>(path), _factory(factory) {}

    std::list<T*> load() const noexcept override {
        std::fstream f(downloader<T>::get_path());
        std::list<T*> cont;
        std::string temp;
        int id;
        std::stringstream strstr;
        if (f.good()) {
            while (!f.eof()) {
                std::getline(f, temp);
                if (temp.empty())
                    continue;
                int it = temp.find(' ');
                id = std::stoi(temp.substr(0, it));
                cont.push_back(_factory->get(ID(id))(temp));
            }
        }
        return cont;
    }
};