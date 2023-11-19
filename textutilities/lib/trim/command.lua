function entrypoint()
    local value = text

    if value == nil then
        info("")
        return ""
    end

    local result = value:match'^()%s*$' and '' or value:match'^%s*(.*%S)'
    info(result)
    return result
end