# Copyright (c) 2012, the Dart project authors.  Please see the AUTHORS file
# for details. All rights reserved. Use of this source code is governed by a
# BSD-style license that can be found in the LICENSE file.

# IMPORTANT:
# Before adding or updating dependencies, please review the documentation here:
# https://github.com/dart-lang/sdk/wiki/Adding-and-Updating-Dependencies
#
# Packages can be rolled to the latest version with `tools/manage_deps.dart`.
# There is some lag time between a commit landing in github and reaching the
# google hosted clones.
#
# For example
#
#     dart tools/manage_deps.dart bump third_party/pkg/dart_style

allowed_hosts = [
  'boringssl.googlesource.com',
  'chrome-infra-packages.appspot.com',
  'chromium.googlesource.com',
  'dart.googlesource.com',
  'dart-internal.googlesource.com',
  'fuchsia.googlesource.com',
]

vars = {
  # The dart_root is the root of our sdk checkout. This is normally
  # simply sdk, but if using special gclient specs it can be different.
  "dart_root": "sdk",

  # We use mirrors of all github repos to guarantee reproducibility and
  # consistency between what users see and what the bots see.
  # We need the mirrors to not have 100+ bots pulling github constantly.
  # We mirror our github repos on Dart's git servers.
  # DO NOT use this var if you don't see a mirror here:
  #   https://dart.googlesource.com/
  "dart_git": "https://dart.googlesource.com/",
  "dart_internal_git": "https://dart-internal.googlesource.com",
  # If the repo you want to use is at github.com/dart-lang, but not at
  # dart.googlesource.com, please file an issue
  # on github and add the label 'area-infrastructure'.
  # When the repo is mirrored, you can add it to this DEPS file.

  # Chromium git
  "chromium_git": "https://chromium.googlesource.com",
  "fuchsia_git": "https://fuchsia.googlesource.com",

  # Checked-in SDK version. The checked-in SDK is a Dart SDK distribution in a
  # cipd package used to run Dart scripts in the build and test infrastructure.
  "sdk_tag": "version:2.18.0",

  # co19 is a cipd package. Use update.sh in tests/co19[_2] to update these
  # hashes.
  "co19_rev": "83feddb44881181ad8f2487080dafe0909517b09",
  # This line prevents conflicts when both packages are rolled simultaneously.
  "co19_2_rev": "17f2b4079f55bb5beb8f8301970089c290590ae4",

  # The internal benchmarks to use. See go/dart-benchmarks-internal
  "benchmarks_internal_rev": "599aa474a03c37be146f82dfbad85f34f25ffa47",
  "checkout_benchmarks_internal": False,

  # Checkout Android dependencies only on Mac and Linux.
  "download_android_deps":
    "host_os == mac or (host_os == linux and host_cpu == x64)",

  # Checkout extra javascript engines for testing or benchmarking.
  # d8, the V8 shell, is always checked out.
  "checkout_javascript_engines": False,
  "d8_tag": "version:10.7.157",
  "jsshell_tag": "version:95.0",

  # As Flutter does, we use Fuchsia's GN and Clang toolchain. These revision
  # should be kept up to date with the revisions pulled by the Flutter engine.
  # The list of revisions for these tools comes from Fuchsia, here:
  # https://fuchsia.googlesource.com/integration/+/HEAD/toolchain
  # If there are problems with the toolchain, contact fuchsia-toolchain@.
  "clang_version": "git_revision:f85c1f3b7c0bda64aef12201e2f5bbad6028582d",
  "gn_version": "git_revision:0bcd37bd2b83f1a9ee17088037ebdfe6eab6d31a",

  # Update from https://chrome-infra-packages.appspot.com/p/fuchsia/sdk/gn
  "fuchsia_sdk_version": "git_revision:8658717573be7924d71b88c3d404ea2b4ca4984b",

  # Ninja, runs the build based on files generated by GN.
  "ninja_tag": "version:2@1.11.1.chromium.4",

  # Scripts that make 'git cl format' work.
  "clang_format_scripts_rev": "bb994c6f067340c1135eb43eed84f4b33cfa7397",

  "gperftools_revision": "bf8b714bf5075d0a6f2f28504b43095e2b1e11c5",

  # Revisions of /third_party/* dependencies.
  # Note that putting an EOL comment after a dependency below will prevent the
  # 'tools/rev_sdk_deps.dart' tool from attempting to rev to a newer revision.

  "args_rev": "80d4abbd6b38b79bcdbc411b4b517628c7611232",
  "async_rev": "f3ed5f690e2ec9dbe1bfc5184705575b4f6480e5",
  "bazel_worker_rev": "03717ca4c2bbf1d74f26c89673426e076288242a",
  "benchmark_harness_rev": "6a116758f2b96e92659194bcda990f42106a01d3",
  "boolean_selector_rev": "1d3565e2651d16566bb556955b96ea75018cbd0c",
  "boringssl_gen_rev": "ced85ef0a00bbca77ce5a91261a5f2ae61b1e62f",
  "boringssl_rev": "87f316d7748268eb56f2dc147bd593254ae93198",
  "browser-compat-data_tag": "ac8cae697014da1ff7124fba33b0b4245cc6cd1b", # v1.0.22
  "browser_launcher_rev": "981ca8847dd2b0fe022f9e742045cfb8f214d35f",
  "characters_rev": "559755d67af2c78b9beaaeb7ca57d7c4ae0b836d",
  "chrome_rev": "19997",
  "cli_util_rev": "b0adbba89442b2ea6fef39c7a82fe79cb31e1168",
  "clock_rev": "97026d1657566bb0c9f5a33642712ec350e45084",
  "collection_rev": "efd709fc1760a595f8575f4137a1847de1b49d76",
  "convert_rev": "4feeb10d2f26d22eab461469da0739a57d001edf",
  "crypto_rev": "7cf89d35b3d90786d9f7f75211b3b3cd7e4d173f",
  "csslib_rev": "ba2eb2d80530eedefadaade338a09c2dd60410f3",

  # Note: Updates to dart_style have to be coordinated with the infrastructure
  # team so that the internal formatter `tools/sdks/dart-sdk/bin/dart format`
  # matches the version here. Please follow this process to make updates:
  #
  # * Create a commit that updates the version here to the desired version and
  #   adds any appropriate CHANGELOG text.
  # * Send that to eng-prod to review. They will update the checked-in SDK
  #   and land the review.
  #
  # For more details, see https://github.com/dart-lang/sdk/issues/30164.
  "dart_style_rev": "f79a9828ad07e50d6e8352ac154cc16eb4d78d5c", # manually rev'd

  "dartdoc_rev": "3cd12f981c585f5744d169a1be2178e8ff6804e0",
  "devtools_rev": "b21cd59f1f6bb60cacd59ba39e376d2a50d82f74",
  "ffi_rev": "fb5f2667826c0900e551d19101052f84e35f41bf",
  "file_rev": "b2e31cb6ef40b223701dbfa0b907fe58468484d7",
  "fixnum_rev": "e0b17cc1f639c55a9c24947392c64b5a68992535",
  "glob_rev": "ee812790f4d98587a363e65d5af484ed9c6943f8",
  "html_rev": "0bf601959ac98e6cdf1925a1cdab70bd6a5ddc45",
  "http_multi_server_rev": "20bf079c8955d1250a45afb9cb096472a724a551",
  "http_parser_rev": "c73967535ce31120e218120f70ef98cc22688c82",
  "http_rev": "738a55b20e391c5a526b86bf4b02af6b7745b494",
  "icu_rev": "81d656878ec611cb0b42d52c82e9dae93920d9ba",
  "intl_rev": "dda8ade30e8865843c6650a20a18bbf94387adee",
  "jinja2_rev": "2222b31554f03e62600cd7e383376a7c187967a1",
  "json_rpc_2_rev": "805e6536dd961d66f6b8cd46d8f3e61774f957c9",
  "linter_rev": "f2c55484e8ebda0aec8c2fea637b3bd5b17258ca", # 1.28.0
  "lints_rev": "8294e5648ab49474541527e2911e72e4c5aefe55",
  "logging_rev": "f322480fb9d9e83e677c08db6d09067059f7ff74",
  "markdown_rev": "93d0eee771f6355be6737c2a865f613f6b105bf1",
  "markupsafe_rev": "8f45f5cfa0009d2a70589bcda0349b8cb2b72783",
  "matcher_rev": "6a9b83bbd73e50df2058b3e8e4aa301df49569c6",
  "mime_rev": "bf041aa372a27aae6f94e185aa0af3932b9de98b",
  "mockito_rev": "02ad6c793d9ea970b5cc892f45a55d12d8ebf4e8",
  "oauth2_rev": "199ebf15cbd5b07958438184f32e41c4447a57bf",
  "package_config_rev": "cff98c90acc457a3b0750f0a7da0e351a35e5d0c",
  "path_rev": "9955b27b9bb98d87591208e19eb01c51d29fd467",
  "ply_rev": "604b32590ffad5cbb82e4afef1d305512d06ae93",
  "pool_rev": "fa84ddd0e39f45bf3f09dcc5d6b9fbdda7820fef",
  "protobuf_rev": "ba29983968de5b54196c6c2a5cff1afbdda24ae2",
  "pub_rev": "b9afe9270c24d040b8ae465b4b37ba4f7f4b4cc5", # manually rev'd
  "pub_semver_rev": "28159b8c5b96fc2709d0904389d7932880f68659",
  "root_certificates_rev": "692f6d6488af68e0121317a9c2c9eb393eb0ee50",
  "shelf_rev": "39d820d4e32fc99c65f562786097487d597dcee1",
  "source_map_stack_trace_rev": "8d8078fcc81c8f7936805cd277198493e0b7fc62",
  "source_maps_rev": "b031e2cdbef5675ab9a92025202d323a5e7cc526",
  "source_span_rev": "ff03af16474ce91c89eb3bc28182866f4cb6dfb0",
  "sse_rev": "283568dd4865cc51e25370ed107fcbdb68759c22",
  "stack_trace_rev": "dce00134f6558086e8963e37d0b1ba0830862c01",
  "stream_channel_rev": "a5129ca44322a7024074ca38fb98e343dcb638c7",
  "string_scanner_rev": "2d84b16d8ae03c3a8c2417b71abe0fe6de7d8bf6",
  "sync_http_rev": "f5c1f18f579752112870fa2f1860470d28c6f605",
  "term_glyph_rev": "ec7cf7bb51ebb7d55760a1359f6697690dbc06ba",
  "test_descriptor_rev": "66f14ce9159f425da000ad105e0b890fe396c2b7",
  "test_process_rev": "068f9f83180014dd587a20af0caa9b2c22431141",
  "test_reflective_loader_rev": "ef934b7a894d78601ba67d8f6207bd4505690456",
  "test_rev": "f704d5afe9667ee1cc35b8575822629091fd6441",
  "typed_data_rev": "6369490ede1c87a4a5758304a606a6e4eee364b9",
  "usage_rev": "9a98c89163c7122bf946954209a69718300392d9",
  "vector_math_rev": "1eee95b15e5d35cf519514cc253037b19705fb7a",
  "watcher_rev": "32591071a83f632478e702f67e29de6e54428ce9",
  "web_components_rev": "8f57dac273412a7172c8ade6f361b407e2e4ed02",
  "web_socket_channel_rev": "4b46c0c4196a5e76c2b0e2589ed37de247d35938",
  "WebCore_rev": "bcb10901266c884e7b3740abc597ab95373ab55c",
  "webdev_rev": "a02f073aecb4c4e7befdf4c1fcc4c83e67af8bf2",
  "webdriver_rev": "f56cc6a2f9612a0a13fec4282dc61b90df384033",
  "webkit_inspection_protocol_rev": "b825c8f6a12200d619729903207ac826cce278da",
  "yaml_edit_rev": "01589b3ce447b03aed991db49f1ec6445ad5476d",
  "yaml_rev": "fda5b15692ccfa0feb7793a27fe3829b3d0f77fa",
  "zlib_rev": "27c2f474b71d0d20764f86f60ef8b00da1a16cda",

  # Windows deps
  "crashpad_rev": "bf327d8ceb6a669607b0dbab5a83a275d03f99ed",
  "minichromium_rev": "8d641e30a8b12088649606b912c2bc4947419ccc",
  "googletest_rev": "f854f1d27488996dc8a6db3c9453f80b02585e12",

  # Pinned browser versions used by the testing infrastructure. These are not
  # meant to be downloaded by users for local testing.
  "download_chrome": False,
  "chrome_tag": "101.0.4951.41",
  "download_firefox": False,
  "firefox_tag": "98.0.2",

  # Emscripten is used in dart2wasm tests.
  "download_emscripten": False,
  "emsdk_rev": "e41b8c68a248da5f18ebd03bd0420953945d52ff",
  "emsdk_ver": "3.1.3",
}

gclient_gn_args_file = Var("dart_root") + '/build/config/gclient_args.gni'
gclient_gn_args = [
]

deps = {
  # Stuff needed for GN build.
  Var("dart_root") + "/buildtools/clang_format/script":
    Var("chromium_git") + "/chromium/llvm-project/cfe/tools/clang-format.git" +
    "@" + Var("clang_format_scripts_rev"),

  Var("dart_root") + "/benchmarks-internal": {
    "url": Var("dart_internal_git") + "/benchmarks-internal.git" +
           "@" + Var("benchmarks_internal_rev"),
    "condition": "checkout_benchmarks_internal",
  },
  Var("dart_root") + "/tools/sdks": {
      "packages": [{
          "package": "dart/dart-sdk/${{platform}}",
          "version": Var("sdk_tag"),
      }],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/d8": {
      "packages": [{
          "package": "dart/d8",
          "version": Var("d8_tag"),
      }],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/firefox_jsshell": {
      "packages": [{
          "package": "dart/third_party/jsshell/${{platform}}",
          "version": Var("jsshell_tag"),
      }],
      "condition": "checkout_javascript_engines",
      "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/devtools": {
      "packages": [{
          "package": "dart/third_party/flutter/devtools",
          "version": "git_revision:" + Var("devtools_rev"),
      }],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/tests/co19/src": {
      "packages": [{
          "package": "dart/third_party/co19",
          "version": "git_revision:" + Var("co19_rev"),
      }],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/tests/co19_2/src": {
      "packages": [{
          "package": "dart/third_party/co19/legacy",
          "version": "git_revision:" + Var("co19_2_rev"),
      }],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/markupsafe":
      Var("chromium_git") + "/chromium/src/third_party/markupsafe.git" +
      "@" + Var("markupsafe_rev"),
  Var("dart_root") + "/third_party/babel": {
      "packages": [{
          "package": "dart/third_party/babel",
          "version": "version:7.4.5",
      }],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/zlib":
      Var("chromium_git") + "/chromium/src/third_party/zlib.git" +
      "@" + Var("zlib_rev"),

  Var("dart_root") + "/third_party/boringssl":
      Var("dart_git") + "boringssl_gen.git" + "@" + Var("boringssl_gen_rev"),
  Var("dart_root") + "/third_party/boringssl/src":
      "https://boringssl.googlesource.com/boringssl.git" +
      "@" + Var("boringssl_rev"),

  Var("dart_root") + "/third_party/gsutil": {
      "packages": [{
          "package": "infra/3pp/tools/gsutil",
          "version": "version:2@5.5",
      }],
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/root_certificates":
      Var("dart_git") + "root_certificates.git" +
      "@" + Var("root_certificates_rev"),

  Var("dart_root") + "/third_party/emsdk":
      Var("dart_git") + "external/github.com/emscripten-core/emsdk.git" +
      "@" + Var("emsdk_rev"),

  Var("dart_root") + "/third_party/jinja2":
      Var("chromium_git") + "/chromium/src/third_party/jinja2.git" +
      "@" + Var("jinja2_rev"),

  Var("dart_root") + "/third_party/ply":
      Var("chromium_git") + "/chromium/src/third_party/ply.git" +
      "@" + Var("ply_rev"),

  Var("dart_root") + "/third_party/icu":
      Var("chromium_git") + "/chromium/deps/icu.git" +
      "@" + Var("icu_rev"),

  Var("dart_root") + "/third_party/WebCore":
      Var("dart_git") + "webcore.git" + "@" + Var("WebCore_rev"),

  Var("dart_root") + "/third_party/mdn/browser-compat-data/src":
      Var('chromium_git') + '/external/github.com/mdn/browser-compat-data' +
      "@" + Var("browser-compat-data_tag"),

  Var("dart_root") + "/third_party/tcmalloc/gperftools":
      Var('chromium_git') + '/external/github.com/gperftools/gperftools.git' +
      "@" + Var("gperftools_revision"),

  Var("dart_root") + "/third_party/pkg/args":
      Var("dart_git") + "args.git" + "@" + Var("args_rev"),
  Var("dart_root") + "/third_party/pkg/async":
      Var("dart_git") + "async.git" + "@" + Var("async_rev"),
  Var("dart_root") + "/third_party/pkg/bazel_worker":
      Var("dart_git") + "bazel_worker.git" + "@" + Var("bazel_worker_rev"),
  Var("dart_root") + "/third_party/pkg/benchmark_harness":
      Var("dart_git") + "benchmark_harness.git" + "@" +
      Var("benchmark_harness_rev"),
  Var("dart_root") + "/third_party/pkg/boolean_selector":
      Var("dart_git") + "boolean_selector.git" +
      "@" + Var("boolean_selector_rev"),
  Var("dart_root") + "/third_party/pkg/browser_launcher":
      Var("dart_git") + "browser_launcher.git" + "@" + Var("browser_launcher_rev"),
  Var("dart_root") + "/third_party/pkg/characters":
      Var("dart_git") + "characters.git" + "@" + Var("characters_rev"),
  Var("dart_root") + "/third_party/pkg/cli_util":
      Var("dart_git") + "cli_util.git" + "@" + Var("cli_util_rev"),
  Var("dart_root") + "/third_party/pkg/clock":
      Var("dart_git") + "clock.git" + "@" + Var("clock_rev"),
  Var("dart_root") + "/third_party/pkg/collection":
      Var("dart_git") + "collection.git" + "@" + Var("collection_rev"),
  Var("dart_root") + "/third_party/pkg/convert":
      Var("dart_git") + "convert.git" + "@" + Var("convert_rev"),
  Var("dart_root") + "/third_party/pkg/crypto":
      Var("dart_git") + "crypto.git" + "@" + Var("crypto_rev"),
  Var("dart_root") + "/third_party/pkg/csslib":
      Var("dart_git") + "csslib.git" + "@" + Var("csslib_rev"),
  Var("dart_root") + "/third_party/pkg/dart_style":
      Var("dart_git") + "dart_style.git" + "@" + Var("dart_style_rev"),
  Var("dart_root") + "/third_party/pkg/dartdoc":
      Var("dart_git") + "dartdoc.git" + "@" + Var("dartdoc_rev"),
  Var("dart_root") + "/third_party/pkg/ffi":
      Var("dart_git") + "ffi.git" + "@" + Var("ffi_rev"),
  Var("dart_root") + "/third_party/pkg/fixnum":
      Var("dart_git") + "fixnum.git" + "@" + Var("fixnum_rev"),
  Var("dart_root") + "/third_party/pkg/file":
      Var("dart_git") + "external/github.com/google/file.dart"
      + "@" + Var("file_rev"),
  Var("dart_root") + "/third_party/pkg/glob":
      Var("dart_git") + "glob.git" + "@" + Var("glob_rev"),
  Var("dart_root") + "/third_party/pkg/html":
      Var("dart_git") + "html.git" + "@" + Var("html_rev"),
  Var("dart_root") + "/third_party/pkg/http":
      Var("dart_git") + "http.git" + "@" + Var("http_rev"),
  Var("dart_root") + "/third_party/pkg/http_multi_server":
      Var("dart_git") + "http_multi_server.git" +
      "@" + Var("http_multi_server_rev"),
  Var("dart_root") + "/third_party/pkg/http_parser":
      Var("dart_git") + "http_parser.git" + "@" + Var("http_parser_rev"),
  Var("dart_root") + "/third_party/pkg/intl":
      Var("dart_git") + "intl.git" + "@" + Var("intl_rev"),
  Var("dart_root") + "/third_party/pkg/json_rpc_2":
      Var("dart_git") + "json_rpc_2.git" + "@" + Var("json_rpc_2_rev"),
  Var("dart_root") + "/third_party/pkg/linter":
      Var("dart_git") + "linter.git" + "@" + Var("linter_rev"),
  Var("dart_root") + "/third_party/pkg/lints":
      Var("dart_git") + "lints.git" + "@" + Var("lints_rev"),
  Var("dart_root") + "/third_party/pkg/logging":
      Var("dart_git") + "logging.git" + "@" + Var("logging_rev"),
  Var("dart_root") + "/third_party/pkg/markdown":
      Var("dart_git") + "markdown.git" + "@" + Var("markdown_rev"),
  Var("dart_root") + "/third_party/pkg/matcher":
      Var("dart_git") + "matcher.git" + "@" + Var("matcher_rev"),
  Var("dart_root") + "/third_party/pkg/mime":
      Var("dart_git") + "mime.git" + "@" + Var("mime_rev"),
  Var("dart_root") + "/third_party/pkg/mockito":
      Var("dart_git") + "mockito.git" + "@" + Var("mockito_rev"),
  Var("dart_root") + "/third_party/pkg/oauth2":
      Var("dart_git") + "oauth2.git" + "@" + Var("oauth2_rev"),
  Var("dart_root") + "/third_party/pkg/package_config":
      Var("dart_git") + "package_config.git" +
      "@" + Var("package_config_rev"),
  Var("dart_root") + "/third_party/pkg/path":
      Var("dart_git") + "path.git" + "@" + Var("path_rev"),
  Var("dart_root") + "/third_party/pkg/pool":
      Var("dart_git") + "pool.git" + "@" + Var("pool_rev"),
  Var("dart_root") + "/third_party/pkg/protobuf":
       Var("dart_git") + "protobuf.git" + "@" + Var("protobuf_rev"),
  Var("dart_root") + "/third_party/pkg/pub_semver":
      Var("dart_git") + "pub_semver.git" + "@" + Var("pub_semver_rev"),
  Var("dart_root") + "/third_party/pkg/pub":
      Var("dart_git") + "pub.git" + "@" + Var("pub_rev"),
  Var("dart_root") + "/third_party/pkg/shelf":
      Var("dart_git") + "shelf.git" + "@" + Var("shelf_rev"),
  Var("dart_root") + "/third_party/pkg/source_maps":
      Var("dart_git") + "source_maps.git" + "@" + Var("source_maps_rev"),
  Var("dart_root") + "/third_party/pkg/source_span":
      Var("dart_git") + "source_span.git" + "@" + Var("source_span_rev"),
  Var("dart_root") + "/third_party/pkg/source_map_stack_trace":
      Var("dart_git") + "source_map_stack_trace.git" +
      "@" + Var("source_map_stack_trace_rev"),
  Var("dart_root") + "/third_party/pkg/sse":
      Var("dart_git") + "sse.git" + "@" + Var("sse_rev"),
  Var("dart_root") + "/third_party/pkg/stack_trace":
      Var("dart_git") + "stack_trace.git" + "@" + Var("stack_trace_rev"),
  Var("dart_root") + "/third_party/pkg/stream_channel":
      Var("dart_git") + "stream_channel.git" +
      "@" + Var("stream_channel_rev"),
  Var("dart_root") + "/third_party/pkg/string_scanner":
      Var("dart_git") + "string_scanner.git" +
      "@" + Var("string_scanner_rev"),
  Var("dart_root") + "/third_party/pkg/sync_http":
      Var("dart_git") + "sync_http.git" + "@" + Var("sync_http_rev"),
  Var("dart_root") + "/third_party/pkg/term_glyph":
      Var("dart_git") + "term_glyph.git" + "@" + Var("term_glyph_rev"),
  Var("dart_root") + "/third_party/pkg/test":
      Var("dart_git") + "test.git" + "@" + Var("test_rev"),
  Var("dart_root") + "/third_party/pkg/test_descriptor":
      Var("dart_git") + "test_descriptor.git" + "@" + Var("test_descriptor_rev"),
  Var("dart_root") + "/third_party/pkg/test_process":
      Var("dart_git") + "test_process.git" + "@" + Var("test_process_rev"),
  Var("dart_root") + "/third_party/pkg/test_reflective_loader":
      Var("dart_git") + "test_reflective_loader.git" +
      "@" + Var("test_reflective_loader_rev"),
  Var("dart_root") + "/third_party/pkg/typed_data":
      Var("dart_git") + "typed_data.git" + "@" + Var("typed_data_rev"),
  Var("dart_root") + "/third_party/pkg/usage":
      Var("dart_git") + "usage.git" + "@" + Var("usage_rev"),
  Var("dart_root") + "/third_party/pkg/vector_math":
      Var("dart_git") + "external/github.com/google/vector_math.dart.git" +
      "@" + Var("vector_math_rev"),
  Var("dart_root") + "/third_party/pkg/watcher":
      Var("dart_git") + "watcher.git" + "@" + Var("watcher_rev"),
  Var("dart_root") + "/third_party/pkg/web_components":
      Var("dart_git") + "web-components.git" +
      "@" + Var("web_components_rev"),
  Var("dart_root") + "/third_party/pkg/webdev":
      Var("dart_git") + "webdev.git" + "@" + Var("webdev_rev"),
  Var("dart_root") + "/third_party/pkg/webdriver":
      Var("dart_git") + "external/github.com/google/webdriver.dart.git" +
      "@" + Var("webdriver_rev"),
  Var("dart_root") + "/third_party/pkg/webkit_inspection_protocol":
      Var("dart_git") + "external/github.com/google/webkit_inspection_protocol.dart.git" +
      "@" + Var("webkit_inspection_protocol_rev"),

  Var("dart_root") + "/third_party/pkg/web_socket_channel":
      Var("dart_git") + "web_socket_channel.git" +
      "@" + Var("web_socket_channel_rev"),
  Var("dart_root") + "/third_party/pkg/yaml_edit":
      Var("dart_git") + "yaml_edit.git" + "@" + Var("yaml_edit_rev"),
  Var("dart_root") + "/third_party/pkg/yaml":
      Var("dart_git") + "yaml.git" + "@" + Var("yaml_rev"),

  Var("dart_root") + "/buildtools/linux-x64/clang": {
      "packages": [
          {
              "package": "fuchsia/third_party/clang/linux-amd64",
              "version": Var("clang_version"),
          },
      ],
      "condition": "host_cpu == x64 and host_os == linux",
      "dep_type": "cipd",
  },
  Var("dart_root") + "/buildtools/mac-x64/clang": {
      "packages": [
          {
              "package": "fuchsia/third_party/clang/mac-amd64",
              "version": Var("clang_version"),
          },
      ],
      "condition": "host_os == mac", # On ARM64 Macs too because Goma doesn't support the host-arm64 toolchain.
      "dep_type": "cipd",
  },
  Var("dart_root") + "/buildtools/win-x64/clang": {
      "packages": [
          {
              "package": "fuchsia/third_party/clang/windows-amd64",
              "version": Var("clang_version"),
          },
      ],
      "condition": "host_cpu == x64 and host_os == win",
      "dep_type": "cipd",
  },
  Var("dart_root") + "/buildtools/linux-arm64/clang": {
      "packages": [
          {
              "package": "fuchsia/third_party/clang/linux-arm64",
              "version": Var("clang_version"),
          },
      ],
      "condition": "host_os == 'linux' and host_cpu == 'arm64'",
      "dep_type": "cipd",
  },
  Var("dart_root") + "/buildtools/mac-arm64/clang": {
      "packages": [
          {
              "package": "fuchsia/third_party/clang/mac-arm64",
              "version": Var("clang_version"),
          },
      ],
      "condition": "host_os == 'mac' and host_cpu == 'arm64'",
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/webdriver/chrome": {
    "packages": [
      {
        "package": "dart/third_party/chromedriver/${{platform}}",
        "version": "version:" + Var("chrome_tag"),
      }
    ],
    "condition": "host_cpu == 'x64'",
    "dep_type": "cipd",
  },

  Var("dart_root") + "/buildtools": {
      "packages": [
          {
              "package": "gn/gn/${{platform}}",
              "version": Var("gn_version"),
          },
      ],
      "dep_type": "cipd",
  },

  Var("dart_root") + "/buildtools/ninja": {
      "packages": [{
          "package": "infra/3pp/tools/ninja/${{platform}}",
          "version": Var("ninja_tag"),
      }],
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/android_tools/ndk": {
      "packages": [
          {
            "package": "flutter/android/ndk/${{os}}-amd64",
            "version": "version:r21.0.6113669"
          }
      ],
      "condition": "download_android_deps",
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/android_tools/sdk/build-tools": {
      "packages": [
          {
            "package": "flutter/android/sdk/build-tools/${{os}}-amd64",
            "version": "version:30.0.1"
          }
      ],
      "condition": "download_android_deps",
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/android_tools/sdk/platform-tools": {
     "packages": [
          {
            "package": "flutter/android/sdk/platform-tools/${{os}}-amd64",
            "version": "version:29.0.2"
          }
      ],
      "condition": "download_android_deps",
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/android_tools/sdk/platforms": {
      "packages": [
          {
            "package": "flutter/android/sdk/platforms",
            "version": "version:30r3"
          }
      ],
      "condition": "download_android_deps",
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/android_tools/sdk/tools": {
      "packages": [
          {
            "package": "flutter/android/sdk/tools/${{os}}-amd64",
            "version": "version:26.1.1"
          }
      ],
      "condition": "download_android_deps",
      "dep_type": "cipd",
  },

  Var("dart_root") + "/third_party/fuchsia/sdk/mac": {
    "packages": [
      {
      "package": "fuchsia/sdk/gn/mac-amd64",
      "version": Var("fuchsia_sdk_version"),
      }
    ],
    "condition": 'host_os == "mac" and host_cpu == "x64"',
    "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/fuchsia/sdk/linux": {
    "packages": [
      {
      "package": "fuchsia/sdk/gn/linux-amd64",
      "version": Var("fuchsia_sdk_version"),
      }
    ],
    "condition": 'host_os == "linux" and host_cpu == "x64"',
    "dep_type": "cipd",
  },

  Var("dart_root") + "/pkg/front_end/test/fasta/types/benchmark_data": {
    "packages": [
      {
        "package": "dart/cfe/benchmark_data",
        "version": "sha1sum:5b6e6dfa33b85c733cab4e042bf46378984d1544",
      }
    ],
    "dep_type": "cipd",
  },

  # TODO(37531): Remove these cipd packages and build with sdk instead when
  # benchmark runner gets support for that.
  Var("dart_root") + "/benchmarks/FfiBoringssl/native/out/": {
      "packages": [
          {
              "package": "dart/benchmarks/ffiboringssl",
              "version": "commit:a86c69888b9a416f5249aacb4690a765be064969",
          },
      ],
      "dep_type": "cipd",
  },
  Var("dart_root") + "/benchmarks/FfiCall/native/out/": {
      "packages": [
          {
              "package": "dart/benchmarks/fficall",
              "version": "ebF5aRXKDananlaN4Y8b0bbCNHT1MnkGbWqfpCpiND4C",
          },
      ],
          "dep_type": "cipd",
  },
  Var("dart_root") + "/benchmarks/NativeCall/native/out/": {
      "packages": [
          {
              "package": "dart/benchmarks/nativecall",
              "version": "w1JKzCIHSfDNIjqnioMUPq0moCXKwX67aUfhyrvw4E0C",
          },
      ],
          "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/browsers/chrome": {
      "packages": [
          {
              "package": "dart/browsers/chrome/${{platform}}",
              "version": "version:" + Var("chrome_tag"),
          },
      ],
      "condition": "download_chrome",
      "dep_type": "cipd",
  },
  Var("dart_root") + "/third_party/browsers/firefox": {
      "packages": [
          {
              "package": "dart/browsers/firefox/${{platform}}",
              "version": "version:" + Var("firefox_tag"),
          },
      ],
      "condition": "download_firefox",
      "dep_type": "cipd",
  },
}

deps_os = {
  "win": {
    Var("dart_root") + "/third_party/cygwin":
        Var("chromium_git") + "/chromium/deps/cygwin.git" + "@" +
        "c89e446b273697fadf3a10ff1007a97c0b7de6df",
    Var("dart_root") + "/third_party/crashpad/crashpad":
        Var("chromium_git") + "/crashpad/crashpad.git" + "@" +
        Var("crashpad_rev"),
    Var("dart_root") + "/third_party/mini_chromium/mini_chromium":
        Var("chromium_git") + "/chromium/mini_chromium" + "@" +
        Var("minichromium_rev"),
    Var("dart_root") + "/third_party/googletest":
        Var("fuchsia_git") + "/third_party/googletest" + "@" +
        Var("googletest_rev"),
  }
}

hooks = [
  {
    # Generate the .dart_tool/package_confg.json file.
    'name': 'Generate .dart_tool/package_confg.json',
    'pattern': '.',
    'action': ['python3', 'sdk/tools/generate_package_config.py'],
  },
  {
    # Generate the sdk/version file.
    'name': 'Generate sdk/version',
    'pattern': '.',
    'action': ['python3', 'sdk/tools/generate_sdk_version_file.py'],
  },
  {
    'name': 'sysroot_arm',
    'pattern': '.',
    'condition': 'checkout_linux',
    'action': ['python3', 'sdk/build/linux/sysroot_scripts/install-sysroot.py',
               '--arch=arm'],
  },
  {
    'name': 'sysroot_arm64',
    'pattern': '.',
    'condition': 'checkout_linux',
    'action': ['python3', 'sdk/build/linux/sysroot_scripts/install-sysroot.py',
               '--arch=arm64'],
  },
  {
    'name': 'sysroot_x86',
    'pattern': '.',
    'condition': 'checkout_linux',
    'action': ['python3', 'sdk/build/linux/sysroot_scripts/install-sysroot.py',
               '--arch=x86'],
  },
  {
    'name': 'sysroot_x64',
    'pattern': '.',
    'condition': 'checkout_linux',
    'action': ['python3', 'sdk/build/linux/sysroot_scripts/install-sysroot.py',
               '--arch=x64'],
  },
  {
    'name': 'buildtools',
    'pattern': '.',
    'action': ['python3', 'sdk/tools/buildtools/update.py'],
  },
  {
    # Update the Windows toolchain if necessary.
    'name': 'win_toolchain',
    'pattern': '.',
    'action': ['python3', 'sdk/build/vs_toolchain.py', 'update'],
    'condition': 'checkout_win'
  },
  # Install and activate the empscripten SDK.
  {
    'name': 'install_emscripten',
    'pattern': '.',
    'action': ['python3', 'sdk/third_party/emsdk/emsdk.py', 'install',
        Var('emsdk_ver')],
    'condition': 'download_emscripten'
  },
  {
    'name': 'activate_emscripten',
    'pattern': '.',
    'action': ['python3', 'sdk/third_party/emsdk/emsdk.py', 'activate',
        Var('emsdk_ver')],
    'condition': 'download_emscripten'
  },
]
