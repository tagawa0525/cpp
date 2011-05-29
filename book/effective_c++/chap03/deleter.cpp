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

BOOST_AUTO_TEST_CASE( test_Lock )
{
  class Lock
  {
    public:
      explicit Lock(boost::mutex* pm)
        //:mutexPtr(pm, unlock)
        :mutexPtr(pm)
      {
        pm->lock();
      }
    private:
      std::tr1::shared_ptr<boost::mutex> mutexPtr;
  };

  boost::mutex* mtx;
  Lock* pl = new Lock(mtx);
  BOOST_CHECK(pl == NULL);
}
/*
 * BOOST_AUTO_TEST_CASE( test_Lock2 )
 * {
 *   class Lock
 *   {
 *     public:
 *       explicit Lock(boost::mutex* pm)
 *         //:mutexPtr(pm, unlock)
 *         :mutexPtr(pm)
 *       {
 *         lock(mutexPtr.get());
 *       }
 *       ~Lock()
 *       {
 *         unlock(mutexPtr.get());
 *       }
 *     private:
 *       void lock(boost::mutex* pm)
 *       {
 *         pm->lock();
 *       }
 *       void unlock(boost::mutex* pm)
 *       {
 *         pm->unlock();
 *       }
 *       std::tr1::shared_ptr<boost::mutex> mutexPtr;
 *   };
 *
 *   boost::mutex* mtx;
 *   Lock* pl = new Lock(mtx);
 *   BOOST_CHECK(pl == NULL);
 * }
 */
