#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/tr1/memory.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

void lock  (boost::mutex* pm) { pm->lock(); }
void unlock(boost::mutex* pm) { pm->unlock(); }

class Lock
{
  public:
    explicit Lock(boost::mutex* pm)
      :mutexPtr(pm, unlock)
    {
      lock(mutexPtr.get());
    }
  private:
    std::tr1::shared_ptr<boost::mutex> mutexPtr;
};

BOOST_AUTO_TEST_CASE( test_Lock )
{
  boost::mutex* mtx = new boost::mutex;
  Lock pl(mtx);
}
