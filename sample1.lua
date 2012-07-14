-- C++ 에서 등록한 함수를 호출한다.
result = cpp_func(1, 2)

print("cpp_func(1,2) = "..result)


-- 일반적인 lua 함수를 선언한다.
function lua_func(arg1, arg2)
	return arg1 + arg2
end



