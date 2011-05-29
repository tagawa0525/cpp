#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/tr1/memory.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

BOOST_AUTO_TEST_CASE( test_mutex )
{
  boost::mutex Mtx;
  Mtx.lock();
  Mtx.try_lock();
  Mtx.unlock();
}

BOOST_AUTO_TEST_CASE( test_mutex_row_pointer )
{
  boost::mutex* pMtx = new boost::mutex;
  pMtx->lock();
  pMtx->try_lock();
  pMtx->unlock();
}

BOOST_AUTO_TEST_CASE( test_mutex_shared_pointer )
{
  tr1::shared_ptr<boost::mutex> pMtx(new boost::mutex);
  pMtx.get()->lock();
  pMtx.get()->try_lock();
  pMtx.get()->unlock();
}

/*
class Lock
{
  public:
    Lock(boost::mutex* pm)
    {
      tr1::shared_ptr<boost::mutex> pMtx(pm);
      pm->lock();
    }
    ~Lock()
    {
      pm->unlock();
    }
  private:
    tr1::shared_ptr<boost::mutex> pMtx;
};
BOOST_AUTO_TEST_CASE( test_Lock )
{
  boost::mutex* pm = new boost::mutex;
  Lock l(pm);
}
*/
