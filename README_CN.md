# TuGraph

[[English Version]](README.md)

:mega: **TuGraph 现在在阿里云计算巢提供[免费试用](https://computenest.console.aliyun.com/user/cn-hangzhou/serviceInstanceCreate?ServiceId=service-7b50ea3d20e643da95bf&ServiceVersion=1&isTrial=true) 可参见 [操作指引](https://aliyun-computenest.github.io/quickstart-tugraph/)**。

## 1. 简介
TuGraph 是支持大数据容量、低延迟查找和快速图分析功能的高效图数据库。

主要功能：

- 标签属性图模型
- 完善的 ACID 事务处理
- 内置 34 图分析算法
- 支持全文/主键/二级索引
- OpenCypher 图查询语言
- 基于 C++/Python 的存储过程

性能和可扩展性：

- LDBC SNB世界记录保持者 (2022/9/1 https://ldbcouncil.org/benchmarks/snb/)
- 支持存储多达数十TB的数据
- 每秒访问数百万个顶点
- 快速批量导入

TuGraph的文档在[链接](https://tugraph-db.readthedocs.io/zh_CN/latest)，欢迎访问我们的[官网](https://www.tugraph.org)。

## 2. 快速上手

一个简单的方法是使用docker进行设置，可以在[DockerHub](https://hub.docker.com/u/tugraph)中找到, 名称为`tugraph/tugraph-runtime-[os]:[tugraph version]`,
例如， `tugraph/tugraph-runtime-centos7:3.3.0`。

更多详情请参考[快速上手文档](./docs/zh-CN/source/3.quick-start/1.preparation.md).

## 3. 从源代码编译

建议在Linux系统中构建TuGraph，Docker环境是个不错的选择。如果您想设置一个新的环境，请参考[Dockerfile](ci/images).

以下是编译TuGraph的步骤：

1. 如果需要web接口运行`deps/build_deps.sh`，不需要web接口则运行`SKIP_WEB=1 deps/build_deps.sh`
2. 根据容器系统信息执行`cmake .. -DOURSYSTEM=centos`或者`cmake .. -DOURSYSTEM=ubuntu`，如果需要shell运行lgraph_cypher，加上`-DENABLE_PREDOWNLOAD_DEPENDS_PACKAGE=1`
3. `make`
4. `make package` 或者 `cpack --config CPackConfig.cmake`

示例：`tugraph/tugraph-compile-centos7`Docker环境

```bash
$ git clone --recursive https://github.com/TuGraph-family/tugraph-db.git
$ cd tugraph-db
$ deps/build_deps.sh
$ mkdir build && cd build
$ cmake .. -DOURSYSTEM=centos -DENABLE_PREDOWNLOAD_DEPENDS_PACKAGE=1
$ make
$ make package
```

## 4. 开发

我们已为在DockerHub中编译准备了环境docker镜像，可以帮助开发人员轻松入门，名称为 `tugraph/tugraph-compile-[os]:[compile version]`, 例如， `tugraph/tugraph-compile-centos7:1.1.0`。

可以访问 [技术规划](./docs/zh-CN/source/6.community-manual/5.roadmap.md) 来了解TuGraph进展。

T如需贡献，请阅读 [如何贡献](./docs/zh-CN/source/6.community-manual/1.contributing.md)。

注意：如果您想贡献代码，需要签署[个人贡献者许可协议](./docs/zh-CN/source/6.community-manual/3.individual-cla.md)或者[公司贡献者许可协议](./docs/zh-CN/source/6.community-manual/4.corporate-cla.md)。

## 5. 联系我们

邮箱: tugraph@service.alipay.com

官网: [www.tugraph.org](https://www.tugraph.org)

Github Issue (错误反馈、功能讨论)
[Issue](https://github.com/TuGraph-db/tugraph-db/issues)

Github Discussions (技术讨论)
[Discussions](https://github.com/TuGraph-db/tugraph-db/discussions)

Slack (在线开发沟通):
[TuGraph.slack](https://join.slack.com/t/tugraph/shared_invite/zt-1hha8nuli-bqdkwn~w4zH1vlk0QvqIfg)

钉钉群 (技术交流)

![alert](./docs/images/dingtalk.png)

微信群 (技术交流)

![alert](./docs/images/wechat_tech.png)

微信公众号 (信息发布)

![alert](./docs/images/wechat.png)

