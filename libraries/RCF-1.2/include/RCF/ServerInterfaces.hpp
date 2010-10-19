
//******************************************************************************
// RCF - Remote Call Framework
// Copyright (c) 2005 - 2010, Jarl Lindrud. All rights reserved.
// Consult your license for conditions of use.
// Version: 1.2
// Contact: jarl.lindrud <at> gmail.com 
//******************************************************************************

#ifndef INCLUDE_RCF_SERVERINTERFACES_HPP
#define INCLUDE_RCF_SERVERINTERFACES_HPP

#include <RCF/Idl.hpp>
#include <RCF/SerializationProtocol.hpp>
#include <RCF/TypeTraits.hpp>

#ifdef RCF_USE_SF_SERIALIZATION
#include <SF/string.hpp>
#include <SF/vector.hpp>
#endif

#ifdef RCF_USE_BOOST_SERIALIZATION
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#endif

RCF_BROKEN_COMPILER_TYPE_TRAITS_SPECIALIZATION(std::vector<boost::int32_t>)

namespace RCF {
   

    //--------------------------------------------------------------------------
    // I_ObjectFactory

    RCF_BEGIN(I_ObjectFactory, "")

        RCF_METHOD_R2(
            boost::int32_t, 
                createObject, 
                    const std::string &, 
                    Token &)

        // Deprecated (use I_SessionObjectFactory)
        RCF_METHOD_R1(
            boost::int32_t, 
                createSessionObject, 
                    const std::string &)

        RCF_METHOD_R1(
            boost::int32_t, 
                deleteObject, 
                    const Token &)

        // Deprecated (use I_SessionObjectFactory)
        RCF_METHOD_R0(
            boost::int32_t, 
                deleteSessionObject)

    RCF_END(I_ObjectFactory)


    //--------------------------------------------------------------------------
    // I_SessionObjectFactory

    RCF_BEGIN(I_SessionObjectFactory, "")

        RCF_METHOD_R1(
            boost::int32_t, 
                createSessionObject, 
                    const std::string &)

        RCF_METHOD_R0(
            boost::int32_t, 
                deleteSessionObject)

    RCF_END(I_SessionObjectFactory)
   

    //--------------------------------------------------------------------------
    // I_EndpointBroker

    RCF_BEGIN(I_EndpointBroker, "")

        RCF_METHOD_R3(
            boost::int32_t, 
                openEndpoint, 
                    const std::string &, 
                    const std::string &, 
                    std::string &)

        RCF_METHOD_R2(
            boost::int32_t, 
                closeEndpoint, 
                    const std::string &, 
                    const std::string &)

        RCF_METHOD_R2(
            boost::int32_t, 
                establishEndpointConnection, 
                    const std::string &, 
                    const std::string &)

        RCF_METHOD_R2(
            boost::int32_t, 
                connectToEndpoint, 
                    const std::string &, 
                    const std::string &)

    RCF_END(I_EndpointBroker)
   

    //--------------------------------------------------------------------------
    // I_EndpointServer

    RCF_BEGIN(I_EndpointServer, "")

        RCF_METHOD_V1(
            void, 
                spawnConnections, 
                    boost::uint32_t)

    RCF_END(I_EndpointServer)
   

    //--------------------------------------------------------------------------
    // I_RequestSubscription

    RCF_BEGIN( I_RequestSubscription, "" )

        RCF_METHOD_R1(
            boost::int32_t, 
                requestSubscription, 
                    const std::string &)

    RCF_END(I_RequestSubscription)


    //--------------------------------------------------------------------------
    // I_RequestTransportFilters

    RCF_BEGIN(I_RequestTransportFilters, "")

        RCF_METHOD_R1(
            boost::int32_t, 
                requestTransportFilters, 
                    const std::vector<boost::int32_t> &)

        RCF_METHOD_R1(
            boost::int32_t, 
                queryForTransportFilters, 
                    const std::vector<boost::int32_t> &)

    RCF_END(I_RequestTransportFilters)

} // namespace RCF

#ifdef RCF_USE_PROTOBUF

// This file is generated by running protoc on 
// RCF/include/RCF/protobuf/RcfMessages.proto.
#include <RCF/protobuf/RcfMessages.pb.h>

namespace RCF {

    //--------------------------------------------------------------------------
    // I_ObjectFactoryPb

    RCF_BEGIN(I_ObjectFactoryPb, "")

        RCF_METHOD_R1(
            CreateRemoteObjectResponse, 
                createRemoteObject, 
                    const CreateRemoteObject &)

        RCF_METHOD_V1(
            void, 
                deleteRemoteObject, 
                    const DeleteRemoteObject &)

    RCF_END(I_ObjectFactoryPb)


    //--------------------------------------------------------------------------
    // I_SessionObjectFactoryPb

    RCF_BEGIN(I_SessionObjectFactoryPb, "")
        
        RCF_METHOD_V1(
            void, 
                createSessionObject, 
                    const CreateSessionObject &)

        RCF_METHOD_V1(
            void, 
                deleteSessionObject, 
                    const DeleteSessionObject &)

    RCF_END(I_SessionObjectFactoryPb)


    //--------------------------------------------------------------------------
    // I_RequestSubscriptionPb

    RCF_BEGIN(I_RequestSubscriptionPb, "")

        RCF_METHOD_V1(
            void, 
                requestSubscription, 
                    const RequestSubscription &)
    
    RCF_END(I_RequestSubscriptionPb)


    //--------------------------------------------------------------------------
    // I_RequestTransportFiltersPb

    RCF_BEGIN(I_RequestTransportFiltersPb, "")

        RCF_METHOD_V1(
            void, 
                requestTransportFilters, 
                    const RequestTransportFilters &)

    RCF_END(I_RequestTransportFiltersPb)
    
} // namespace RCF

#endif // RCF_USE_PROTOBUF

#endif // ! INCLUDE_RCF_SERVERINTERFACES_HPP
