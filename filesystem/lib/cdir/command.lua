function entrypoint()
    local res = fs.absolute(workspace.dir)
    info(res)
    return res
end