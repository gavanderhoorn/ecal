// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file string_message_.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _STRING_MESSAGE__H_
#define _STRING_MESSAGE__H_

// TODO Poner en el contexto.

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(string_message__SOURCE)
#define string_message__DllAPI __declspec( dllexport )
#else
#define string_message__DllAPI __declspec( dllimport )
#endif // string_message__SOURCE
#else
#define string_message__DllAPI
#endif
#else
#define string_message__DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}

/*!
 * @brief This class represents the structure string_message_ defined by the user in the IDL file.
 * @ingroup STRING_MESSAGE_
 */
class string_message_
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport string_message_();
    
    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~string_message_();
    
    /*!
     * @brief Copy constructor.
     * @param x Reference to the object string_message_ that will be copied.
     */
    eProsima_user_DllExport string_message_(const string_message_ &x);
    
    /*!
     * @brief Move constructor.
     * @param x Reference to the object string_message_ that will be copied.
     */
    eProsima_user_DllExport string_message_(string_message_ &&x);
    
    /*!
     * @brief Copy assignment.
     * @param x Reference to the object string_message_ that will be copied.
     */
    eProsima_user_DllExport string_message_& operator=(const string_message_ &x);
    
    /*!
     * @brief Move assignment.
     * @param x Reference to the object string_message_ that will be copied.
     */
    eProsima_user_DllExport string_message_& operator=(string_message_ &&x);
    
    /*!
     * @brief This function copies the value in member tid
     * @param _tid New value to be copied in member tid
     */
    inline eProsima_user_DllExport void tid(const std::string &_tid)
    {
        m_tid = _tid;
    }

    /*!
     * @brief This function moves the value in member tid
     * @param _tid New value to be moved in member tid
     */
    inline eProsima_user_DllExport void tid(std::string &&_tid)
    {
        m_tid = std::move(_tid);
    }

    /*!
     * @brief This function returns a constant reference to member tid
     * @return Constant reference to member tid
     */
    inline eProsima_user_DllExport const std::string& tid() const
    {
        return m_tid;
    }

    /*!
     * @brief This function returns a reference to member tid
     * @return Reference to member tid
     */
    inline eProsima_user_DllExport std::string& tid()
    {
        return m_tid;
    }
    /*!
     * @brief This function sets a value in member id
     * @param _id New value for member id
     */
    inline eProsima_user_DllExport void id(int64_t _id)
    {
        m_id = _id;
    }

    /*!
     * @brief This function returns the value of member id
     * @return Value of member id
     */
    inline eProsima_user_DllExport int64_t id() const
    {
        return m_id;
    }

    /*!
     * @brief This function returns a reference to member id
     * @return Reference to member id
     */
    inline eProsima_user_DllExport int64_t& id()
    {
        return m_id;
    }
    /*!
     * @brief This function sets a value in member clock
     * @param _clock New value for member clock
     */
    inline eProsima_user_DllExport void clock(int64_t _clock)
    {
        m_clock = _clock;
    }

    /*!
     * @brief This function returns the value of member clock
     * @return Value of member clock
     */
    inline eProsima_user_DllExport int64_t clock() const
    {
        return m_clock;
    }

    /*!
     * @brief This function returns a reference to member clock
     * @return Reference to member clock
     */
    inline eProsima_user_DllExport int64_t& clock()
    {
        return m_clock;
    }
    /*!
     * @brief This function sets a value in member time
     * @param _time New value for member time
     */
    inline eProsima_user_DllExport void time(int64_t _time)
    {
        m_time = _time;
    }

    /*!
     * @brief This function returns the value of member time
     * @return Value of member time
     */
    inline eProsima_user_DllExport int64_t time() const
    {
        return m_time;
    }

    /*!
     * @brief This function returns a reference to member time
     * @return Reference to member time
     */
    inline eProsima_user_DllExport int64_t& time()
    {
        return m_time;
    }
    /*!
     * @brief This function sets a value in member compressed
     * @param _compressed New value for member compressed
     */
    inline eProsima_user_DllExport void compressed(char _compressed)
    {
        m_compressed = _compressed;
    }

    /*!
     * @brief This function returns the value of member compressed
     * @return Value of member compressed
     */
    inline eProsima_user_DllExport char compressed() const
    {
        return m_compressed;
    }

    /*!
     * @brief This function returns a reference to member compressed
     * @return Reference to member compressed
     */
    inline eProsima_user_DllExport char& compressed()
    {
        return m_compressed;
    }
    /*!
     * @brief This function sets a value in member size
     * @param _size New value for member size
     */
    inline eProsima_user_DllExport void size(int64_t _size)
    {
        m_size = _size;
    }

    /*!
     * @brief This function returns the value of member size
     * @return Value of member size
     */
    inline eProsima_user_DllExport int64_t size() const
    {
        return m_size;
    }

    /*!
     * @brief This function returns a reference to member size
     * @return Reference to member size
     */
    inline eProsima_user_DllExport int64_t& size()
    {
        return m_size;
    }
    /*!
     * @brief This function sets a value in member hash
     * @param _hash New value for member hash
     */
    inline eProsima_user_DllExport void hash(uint64_t _hash)
    {
        m_hash = _hash;
    }

    /*!
     * @brief This function returns the value of member hash
     * @return Value of member hash
     */
    inline eProsima_user_DllExport uint64_t hash() const
    {
        return m_hash;
    }

    /*!
     * @brief This function returns a reference to member hash
     * @return Reference to member hash
     */
    inline eProsima_user_DllExport uint64_t& hash()
    {
        return m_hash;
    }
    /*!
     * @brief This function copies the value in member payload
     * @param _payload New value to be copied in member payload
     */
    inline eProsima_user_DllExport void payload(const std::vector<char> &_payload)
    {
        m_payload = _payload;
    }

    /*!
     * @brief This function moves the value in member payload
     * @param _payload New value to be moved in member payload
     */
    inline eProsima_user_DllExport void payload(std::vector<char> &&_payload)
    {
        m_payload = std::move(_payload);
    }

    /*!
     * @brief This function returns a constant reference to member payload
     * @return Constant reference to member payload
     */
    inline eProsima_user_DllExport const std::vector<char>& payload() const
    {
        return m_payload;
    }

    /*!
     * @brief This function returns a reference to member payload
     * @return Reference to member payload
     */
    inline eProsima_user_DllExport std::vector<char>& payload()
    {
        return m_payload;
    }
    
    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(const string_message_& data, size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;
    
private:
    std::string m_tid;
    int64_t m_id;
    int64_t m_clock;
    int64_t m_time;
    char m_compressed;
    int64_t m_size;
    uint64_t m_hash;
    std::vector<char> m_payload;
};

#endif // _STRING_MESSAGE__H_