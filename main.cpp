#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

using boost::asio::ip::udp;

std::string make_daytime_string()
{
    using namespcae std; // For time_t, time and ctime;
    time_t now = time(0);
    return ctime(&now);
}

class udp_server
{
  public:
    udp_server(boost::asio::io_service &io_server) : socket_(io_service, upd::endpoint(udp::v4), 13)
    {
        start_receive();
    }
private:
void start_receive()
{
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_)
    )
}

  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  boost::array<char, 1> recv_buffer_;
};

int main()
{
    try
    {
        boost::asio::io_service io_service;
    }
}
