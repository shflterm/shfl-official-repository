function entrypoint()
    local path = args[1]
    fs.remove(path);
    print(path .. " has been deleted.");
end

function suggest()
    return {}
end
