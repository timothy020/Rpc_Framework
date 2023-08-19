
# set(SRC_LIST ./calluserservice.cc ../user.pb.cc)
set(SRC_LIST ./callfriendservice.cc ../friendlist.pb.cc)


add_executable(consumer ${SRC_LIST})

# 需要 连接动态库 protobuf  
target_link_libraries(consumer mprpc protobuf pthread)