function entrypoint()
    local value = text

    if value == nil then
        info("")
        return
    end

    value = value:gsub("%a", string.upper, 1)

    info(value)
    return value
end