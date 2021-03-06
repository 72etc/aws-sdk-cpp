add_project(aws-cpp-sdk-route53resolver "C++ SDK for the AWS route53resolver service" aws-cpp-sdk-core)

file(GLOB AWS_ROUTE53RESOLVER_HEADERS
    "include/aws/route53resolver/*.h"
)

file(GLOB AWS_ROUTE53RESOLVER_MODEL_HEADERS
    "include/aws/route53resolver/model/*.h"
)

file(GLOB AWS_ROUTE53RESOLVER_SOURCE
    "source/*.cpp"
)

file(GLOB AWS_ROUTE53RESOLVER_MODEL_SOURCE
    "source/model/*.cpp"
)

file(GLOB ROUTE53RESOLVER_UNIFIED_HEADERS
    ${AWS_ROUTE53RESOLVER_HEADERS}
    ${AWS_ROUTE53RESOLVER_MODEL_HEADERS}
)

file(GLOB ROUTE53RESOLVER_UNITY_SRC
    ${AWS_ROUTE53RESOLVER_SOURCE}
    ${AWS_ROUTE53RESOLVER_MODEL_SOURCE}
)

if(ENABLE_UNITY_BUILD)
    enable_unity_build("ROUTE53RESOLVER" ROUTE53RESOLVER_UNITY_SRC)
endif()

file(GLOB ROUTE53RESOLVER_SRC
    ${ROUTE53RESOLVER_UNIFIED_HEADERS}
    ${ROUTE53RESOLVER_UNITY_SRC}
)

if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
        source_group("Header Files\\aws\\route53resolver" FILES ${AWS_ROUTE53RESOLVER_HEADERS})
        source_group("Header Files\\aws\\route53resolver\\model" FILES ${AWS_ROUTE53RESOLVER_MODEL_HEADERS})
        source_group("Source Files" FILES ${AWS_ROUTE53RESOLVER_SOURCE})
        source_group("Source Files\\model" FILES ${AWS_ROUTE53RESOLVER_MODEL_SOURCE})
    endif(MSVC)
endif()

set(ROUTE53RESOLVER_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

add_library(${PROJECT_NAME} ${LIBTYPE} ${ROUTE53RESOLVER_SRC})
add_library(AWS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_compiler_flags(${PROJECT_NAME})
set_compiler_warnings(${PROJECT_NAME})

if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "AWS_ROUTE53RESOLVER_EXPORTS")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PLATFORM_DEP_LIBS} ${PROJECT_LIBS})


setup_install()

install (FILES ${AWS_ROUTE53RESOLVER_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/route53resolver)
install (FILES ${AWS_ROUTE53RESOLVER_MODEL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/route53resolver/model)

if(PLATFORM_WINDOWS AND MSVC)
    file(GLOB NUGET_FILES "nuget/${PROJECT_NAME}.*.autopkg")
    install (FILES ${NUGET_FILES} DESTINATION nuget)
endif()

do_packaging()


