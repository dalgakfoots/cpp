#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::endpoint endpoint(tcp::v4(), 13);
        tcp::acceptor acceptor(io_service, endpoint);

        std::cout << "Server started" << std::endl;

        for (;;)
        {
            const std::string message_to_send = "Hello From Server";
            boost::asio::ip::tcp::iostream stream;
            std::cout << "Check 1" << std::endl;

            boost::system::error_code ec;
            acceptor.accept(*stream.rdbuf(), ec);

            std::cout << "Check 2" << std::endl;

            if (!ec)
            {
                std::string line;
                std::getline(stream, line);
                std::cout << line << std::endl;

                stream << message_to_send;
                stream << std::endl;
            }
        }

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}