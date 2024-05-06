

#include "includes.h"

// Interface so values can be stored polymophically in a vector
class CacheInterface
{
public:
  virtual ~CacheInterface(){}
  virtual std::string GetName() const = 0;
};

// Stores a cached value and its name
template <class T>
class CachedValue : public CacheInterface
{
public:
  CachedValue(const T & value, const std::string & name):
    _value(value),
    _name(name)
  {
  }

  std::string GetName() const
  {
    return _name;
  }

  void SetValue(const T & value)
  {
    _value = value;
  }

  T _value;
  std::string _name;
};


// Stores the cache results, can be inherited from or held as a member.
class ResultCache
{
public:
  template <class T> void AddToCache(const T & value, const std::string & name)
  {
    // Search if it is there
    for (shared_ptr<CacheInterface> & cache : _cached_items)
    {
      if (cache->GetName() == name)
      {
        shared_ptr<CachedValue<T>> cache_value (boost::reinterpret_pointer_cast<CachedValue<T>>(cache));
        cache_value->_value = value;
        return;
      }
    }

    // Make a new cache value and add it
    shared_ptr<CacheInterface> cached_item(new CachedValue<T>(value, name));
    _cached_items.push_back(cached_item);
  }

  // Returns true if cache exists for a name
  bool IsInCache(const std::string & name)
  {
    for (shared_ptr<CacheInterface> & cache : _cached_items)
    {
      if (cache->GetName() == name)
      {
        return true;
      }
    }
    return false;
  }

  // Reads a value from the cache
  template <class T> void ReadFromCache(T & output, const std::string & name)
  {
    for (shared_ptr<CacheInterface> & cache : _cached_items)
    {
      if (cache->GetName() == name)
      {
        // Is reinterpret cast safe?
        shared_ptr<CachedValue<T>> cache_value (boost::reinterpret_pointer_cast<CachedValue<T>>(cache));
        output = cache_value->_value;
      }
    }
  }

  // Clears the cache values
  void ClearCache()
  {
    _cached_items.clear();
  }

  // Clear cache on copy and assign?


private:
  std::vector<shared_ptr<CacheInterface>> _cached_items;
};

// Macros simplified use in code.
#define IS_IN_CACHE(x) IsInCache(#x)
#define READ_FROM_CACHE(x) ReadFromCache(x, #x)
#define CACHE_RESULT(x) AddToCache(x, #x)
