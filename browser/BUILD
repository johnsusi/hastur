load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "engine",
    srcs = ["engine.cpp"],
    hdrs = ["engine.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//css",
        "//dom",
        "//html",
        "//layout",
        "//protocol",
        "//style",
        "//uri",
        "@spdlog",
    ],
)

cc_test(
    name = "engine_test",
    size = "small",
    srcs = ["engine_test.cpp"],
    deps = [
        ":engine",
        "//etest",
        "//protocol",
        "//uri",
    ],
)

alias(
    name = "browser",
    actual = "gui",
)

cc_binary(
    name = "tui",
    srcs = ["tui.cpp"],
    linkopts = select({
        "@platforms//os:linux": ["-lpthread"],
        "@platforms//os:windows": [],
    }),
    deps = [
        ":engine",
        "//dom",
        "//protocol",
        "//tui",
        "//uri",
        "@spdlog",
    ],
)

cc_binary(
    name = "gui",
    srcs = ["gui.cpp"] + glob(["gui/*"]),
    deps = [
        ":engine",
        "//css",
        "//dom",
        "//gfx",
        "//gfx:opengl",
        "//gfx:sfml",
        "//layout",
        "//os",
        "//protocol",
        "//render",
        "//uri",
        "@fmt",
        "@imgui",
        "@imgui-sfml",
        "@sfml//:graphics",
        "@sfml//:window",
        "@spdlog",
    ],
)
