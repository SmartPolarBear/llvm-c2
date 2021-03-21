#pragma once

template <typename T> class Singleton
{
  public:
    static T &Instance();

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

  protected:
    Singleton()
    {
    }
};

template <typename T> T &Singleton<T>::Instance()
{
    static T inst{};
    return inst;
}
