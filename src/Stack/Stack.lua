--[[
Author: xixi_
Date: 2024-10-27 17:48:03
LastEditors: xixi_
LastEditTime: 2024-10-31 16:53:34
FilePath: /FHMF/src/Modules/xixi/src/Stack/Stack.lua
Copyright (c) 2023-2024 by xixi_ , All Rights Reserved. 
--]]
--------------------------------------------------------------------------------------------------------------------------
Stack = {};
Stack.__index = Stack;
--------------------------------------------------------------------------------------------------------------------------
function Stack:new()
    local instance = {
        ThisData = {},
        ThisTop = 0
    };
    setmetatable(instance, Stack);
    return instance;
end
--------------------------------------------------------------------------------------------------------------------------
function Stack:IsEmpty()
    return self.ThisTop == 0;
end
--------------------------------------------------------------------------------------------------------------------------
function Stack:Push(value)
    self.ThisTop = self.ThisTop + 1;
    self.ThisData[self.ThisTop] = value;
end
--------------------------------------------------------------------------------------------------------------------------
function Stack:Pop()
    if (self:IsEmpty()) then
        return nil; -- 栈为空，返回 nil
    end
    local value = self.ThisData[self.ThisTop];
    self.ThisTop = self.ThisTop - 1;
    return value;
end
--------------------------------------------------------------------------------------------------------------------------
function Stack:Peek()
    if (self:IsEmpty()) then
        return nil; -- 栈为空，返回 nil
    end
    return self.ThisData[self.ThisTop];
end
--------------------------------------------------------------------------------------------------------------------------
function Stack:Print()
    for i = 1, self.ThisTop do
        print(self.ThisData[i]);
    end
end
--------------------------------------------------------------------------------------------------------------------------
-- 使用示例
local Stack = Stack:new();
Stack:Push("NIma");
Stack:Pop();
Stack:Push("Ima");
Stack:Print();
--------------------------------------------------------------------------------------------------------------------------
