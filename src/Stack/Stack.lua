--[[
Author: xixi_
Date: 2024-10-27 17:48:03
LastEditors: xixi_
LastEditTime: 2024-11-11 11:58:33
FilePath: /FHMF/src/Modules/xixi/src/Stack/Stack.lua
Copyright (c) 2020-2024 by xixi_ , All Rights Reserved.
--]]
--------------------------------------------------------------------------------------------------------------------------
Stack = {}; --[[ 栈类 ]]
Stack.__index = Stack; --[[ 元表 ]]
--------------------------------------------------------------------------------------------------------------------------
--[[ 栈构造函数 ]]
function Stack:new()
    local instance = {
        ThisData = {},
        ThisTop = 0
    };
    setmetatable(instance, Stack);
    return instance;
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 判断栈是否空 ]]
function Stack:IsEmpty()
    return self.ThisTop == 0;
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 将`value`推进栈 ]]
function Stack:Push(value)
    self.ThisTop = self.ThisTop + 1;
    self.ThisData[self.ThisTop] = value;
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 向栈顶追加元素 ]]
function Stack:AppendVal(value)
    if (self:IsEmpty()) then
        self:Push(value); --[[ 栈空,直接推入 ]]
        return;
    end
    self.ThisData[self.ThisTop] = self.ThisData[self.ThisTop] .. value; --[[ 栈非空,在末尾追加 ]]
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 弹出栈顶元素 ]]
function Stack:Pop()
    if (self:IsEmpty()) then
        return nil; --[[ 栈为空，返回 nil ]]
    end
    local value = self.ThisData[self.ThisTop];
    self.ThisTop = self.ThisTop - 1;
    return value;
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 返回栈顶元素 ]]
function Stack:Peek()
    if (self:IsEmpty()) then
        return nil; --[[ 栈为空，返回 nil ]]
    end
    return self.ThisData[self.ThisTop];
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 打印栈 ]]
function Stack:Print()
    for i = 1, self.ThisTop, 1 do
        print(self.ThisData[i]);
    end
end
--------------------------------------------------------------------------------------------------------------------------
--[[ 使用示例 ]]
local Stack = Stack:new();
Stack:Push("Fuck YanZiHao");
Stack:Pop();
Stack:AppendVal(" Fuck YanJianKang");
Stack:Print();
--------------------------------------------------------------------------------------------------------------------------
