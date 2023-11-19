function entrypoint()
    local res = fs.absolute(workspace.dir)
    print(res)
    return res
end