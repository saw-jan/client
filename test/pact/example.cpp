#include <iostream>
#include <gtest/gtest.h>
#include <consumer.h>

using namespace testing;
using namespace pact_consumer;
using namespace pact_consumer::matchers;

TEST(Sharing, GetAllShares) {
  auto provider = Pact("client", "oC10");
  provider.pact_directory = "pact";

  provider
    .uponReceiving("a GET request to get all the shares")
    .withRequest("GET", "/ocs/v1.php/apps/files_sharing/api/v1/shares")
    .willRespondWith(200);

  auto result = provider.run_test([] (auto mock_server) {
    std::string url = mock_server->get_url();
    int port = mock_server->get_port();
    std::cout<<url<<std::endl;
    std::cout<<port;
    return ::testing::UnitTest::GetInstance()->current_test_suite()->Passed();
  });
  EXPECT_TRUE(result.is_ok()) << "Test failed";
}

int main(int argc, char **argv) {
  init();
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}