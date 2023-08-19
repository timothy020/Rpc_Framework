
# set(SRC_LIST ./userservice.cc ../user.pb.cc)
set(SRC_LIST ./friendlistservice.cc ../friendlist.pb.cc)

add_executable(provider ${SRC_LIST})

# 需要 连接动态库 protobuf  
target_link_libraries(provider mprpc protobuf pthread)