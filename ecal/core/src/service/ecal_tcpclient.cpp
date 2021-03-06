/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

/**
 * @brief  eCAL tcp server based on asio c++
**/

#include "ecal_tcpclient.h"

namespace eCAL
{
  //////////////////////////////////////////////////////////////////
  // CTcpClient
  //////////////////////////////////////////////////////////////////
  CTcpClient::CTcpClient() : m_created(false), m_connected(false)
  {
  }

  CTcpClient::CTcpClient(const std::string& host_name_, unsigned short port_) : m_created(false)
  {
    Create(host_name_, port_);
  }

  CTcpClient::~CTcpClient()
  {
    Destroy();
  }

  void CTcpClient::Create(const std::string& host_name_, unsigned short port_)
  {
    if (m_created) return;

    m_host_name  = host_name_;
    m_io_service = std::make_shared<asio::io_service>();
    m_socket     = std::make_shared<asio::ip::tcp::socket>(*m_io_service);
    asio::ip::tcp::resolver resolver(*m_io_service);

    try
    {
      asio::connect(*m_socket, resolver.resolve({ host_name_, std::to_string(port_) }));
      m_connected = true;
    }
    catch (std::exception& /*e*/)
    {
      //std::cerr << "CTcpClient::Connect conect exception: " << e.what() << "\n";
      m_connected = false;
    }

    m_created = true;
  }

  void CTcpClient::Destroy()
  {
    if (!m_created) return;

    m_socket     = nullptr;
    m_io_service = nullptr;
    m_connected  = false;

    m_created = false;
  }

  size_t CTcpClient::ExecuteRequest(const std::string& request_, std::string& response_)
  {
    if (!m_created) return 0;

    size_t written(0);
    try
    {
      // send payload to server
      while (written != request_.size())
      {
        written += m_socket->write_some(asio::buffer(request_.c_str() + written, request_.size() - written));
      }
    }
    catch (std::exception& /*e*/)
    {
      //std::cerr << "CTcpClient::ExecuteRequest: Failed to send request: " << e.what() << "\n";
      m_connected = false;
      return 0;
    }

    try
    {
      response_.clear();
      do
      {
        const size_t buffer_size(1024);
        char buffer[buffer_size];
        const size_t bytes_read = m_socket->read_some(asio::buffer(buffer, buffer_size));

        response_ += std::string(buffer, bytes_read);

      } while (m_socket->available());

      return response_.size();
    }
    catch (std::exception& /*e*/)
    {
      //std::cerr << "CTcpClient::ExecuteRequest: Failed to recieve response: " << e.what() << "\n";
      m_connected = false;
      return 0;
    }
  }
};
