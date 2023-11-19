function entrypoint()
    local value = text

    if value == nil then
        info("")
        return
    end

    info(value)
    return value
end